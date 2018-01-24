require 'pdfkit'
require 'nokogiri'
require 'haml'

# config/initializers/pdfkit.rb

PDFKit.configure do |config|
  # Note: Often required for Windows OS configuration
  # config.wkhtmltopdf = '/path/to/wkhtmltopdf'
  
  # Basic configuration/customization
  # config.default_options = {
  #   :page_size => 'Legal',
  #   :print_media_type => true
  # }
  # config.root_url = "http://localhost" # Use only if your external hostname is unavailable on the server.
end

module Jekyll
  class PdfConverter < Converter
    safe true

    priority :low

    def matches(ext)
      ext =~ /\.pdf$/i
    end 

    def output_ext(ext)
      ".pdf"
    end

    def convert(content)
      styled_kit.to_pdf
    end

    protected

    # override to assemble the specific part of the page to print to the PDF document!
    #
    def page
      content
    end

    def styled_kit
      css_files.compact.each do |css_ref|
        kit.stylesheets << css_ref
      end
    end

    def css_files
      []
    end

    def kit
      @kit ||= PDFKit.new(page, :page_size => 'Letter')
    end

    def page_filter
      @page_filter ||= PageFilter.new content
    end

    class PageFilter
      attr_reader :content

      def initialize content
        @content = content
      end

      def doc
        @doc ||= Nokogiri::HTML(content)        
      end

      def layout
        haml %Q{
!!!
  html
    body
      = page_content
}
      end

      def page
        layout.render page_content: page_content        
      end

      # filter out the part of the page to use for PDF document
      # See Nokogiri docs
      # Tutorials: 
      # - http://ruby.bastardsbook.com/chapters/html-parsing/
      # - https://blog.engineyard.com/2010/getting-started-with-nokogiri
      def page_content
        doc.css('section#page-content')
      end
    end
  end
end
