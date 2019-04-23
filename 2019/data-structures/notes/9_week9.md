---
layout: page
course: "sbe201"
category: "notes"
year: "2019"
title:  "Week 9: Hash tables"
by: "Asem"
---

## Revisiting Associative Containers: Hash Tables

We learned earlier how to implement an associative container (i.e dictionary) using a **BST**. In this tutorial, you are introduced a new data structure that can serve as an associative container, i.e hash table. As associative containers are associating keys with values, hash table are also working with the same concept.

In brief, hash table is an array with a principled access patterns. Each element in the array consists of a key and value.

```c++
struct HashElement
{
    char key;
    int value;
};
```

### How do we store elements?

| ![hash](/gallery/Hash_table_3_1_1_0_1_0_0_SP.svg) |
|--|
| A small phone book as a hash table,  Creative Commons: [Jorge Stolfi](https://commons.wikimedia.org/wiki/User:Jorge_Stolfi), [Hash Table \| Wikipedia](https://en.wikipedia.org/wiki/Hash_table) |

**Hash function** is simply transforming element **key** value into an index to store that element in. A simple hash function would typically utilize the following function:

$$ \text{ index } = \text{ key } \% \text{ ARRAY_SIZE }$$

##### Example: Hashing DNA characters

Consider the following table of DNA four bases along with their ascii code values:

| Base | Ascii | Hash0: $ \text{ key } \% \text{ 3 } $| Hash1: $ \text{ key } \% \text{ 5 } $ | Hash2:  $ \text{ key } \% \text{ 13 }$ |
|---|---|---|---|---|
| A | 65 |  2 | 0 | 0 |
| C | 67 | 1 | 2 | 2 |
| G | 71 | 2 | 1 | 6 |
| T | 84 | 0 | 4 | 6 |

As you may have guessed, we will have a critical issue that mapping keys are not necessarily results in unique index for each key. For example when we used `Hash0`, it hashed `A(65)` and `G(71)` with same value. We name this problem in hashing world by **collision**. So, how do we store `A` and `G` then?

Add **collision** to your glossary.


#### Method 1: Chaining

| ![hash](/gallery/Hash_table_5_0_1_1_1_1_1_LL.svg) |
|--|
| Hash collision resolved by separate chaining,  Creative Commons: [Jorge Stolfi](https://commons.wikimedia.org/wiki/User:Jorge_Stolfi), [Hash Table \| Wikipedia](https://en.wikipedia.org/wiki/Hash_table) |

1. We hash the key to an index.
1. All keys mapped to the same index are stored in the same list.

##### Element Structure

```c++
struct HashElement
{
    char key;
    int value;
};
```

##### Table Structure

```c++
struct HashChainingTable
{
    std::array< std::list< HashElement > , 100 > bucket;
};
```

##### Hash Function

```c++
int hash(HashChainingTable &table, char key)
{
    return key % table.bucket.size();
}
```

##### Empty Function

```c++
bool isEmpty(HashChainingTable &table)
{
    for (int i = 0; i < table.bucket.size(); ++i)
        if (!table.bucket[i].empty())
            return false;
    return true;
}
```

##### Size Function

```c++
int size(HashChainingTable &table)
{
    int mSize = 0;
    for (int i = 0; i < table.bucket.size(); ++i)
        mSize += table.bucket[i].size();
    return mSize;
}
```

##### Find Function

```c++
bool find(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (HashElement &element : slot)
        if (element.key == key)
            return true;
    return false;
}
```

##### At Function

```c++
int &at(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (HashElement &element : slot)
        if (element.key == key)
            return element.value;

    std::cout << "Key not found!" << std::endl;
    exit(1);
}
```

##### Insert Function

```c++
void insert(HashChainingTable &table, char key, int value)
{
    if (!find(table, key))
    {
        HashElement newElement{key, value};
        int index = hash(table, key);
        std::list<HashElement> &slot = table.bucket[index];
        slot.push_back(newElement);
    }
}
```

##### Remove Function

```c++
void remove(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (auto it = slot.begin(); it != slot.end(); ++it)
        if (it->key == key)
            slot.erase(it);
}
```

##### Value Function

```c++
int &value(HashChainingTable &table, char key)
{
    if (!find(table, key))
    {
        insert(table, key , 0 );
    }
    return at(table, key);
}
```

##### Clear Function

```c++
void clear(HashChainingTable &table)
{
    for (auto &slot : table.bucket )
        slot.clear();
}
```

##### Print All Function

```c++
void printAll(HashChainingTable &table)
{
    for (auto &slot : table.bucket )
        for (auto &element : slot)
            std::cout << element.key << ":" << element.value << std::endl;
}
```

#### Method 2: Linear Probing

| ![hash](/gallery/Hash_table_5_0_1_1_1_1_0_SP.svg) |
|--|
| Hash collision resolved by open addressing with linear probing,  Creative Commons: [Jorge Stolfi](https://commons.wikimedia.org/wiki/User:Jorge_Stolfi), [Hash Table \| Wikipedia](https://en.wikipedia.org/wiki/Hash_table) |

1. We hash the key to an index.
1. We check if that index is occupied or not by other element:
    1. if occupied, increment the index until you find available slot.
1. Store.

## Map (ADT) on Hash Table

```c++
#include "hash_chaining.hpp"
#include "helpers.hpp"

int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getFileFirstLine( argv[1] );

        auto cMap = hash::create();

        // Complete here!
        for( auto b : dna )
            hash::value( cMap , b )++;

        // Done here!
        hash::printAll( cMap );
    }

    return 0;
}
```


**Clone the code**:

```bash
git clone https://github.com/sbme-tutorials/sbe201-hashes.git
```
## Programming Languages and Research Interests

As an engineer, you should be highly skilled in few programming languages and must also develop a research interest. You are highly recommended to develop research interests in few domains. Research interests makes your cover letter (i.e motivation letter, i.e statement of purpose) very attractive.

**Discussion**: Engineers vs. Programmers

## Domestic Internships

Domestic internships are typically found and admitted through several channels.

1. Networking.
    * [New Survey Reveals 85% of All Jobs are Filled Via Networking](https://www.linkedin.com/pulse/new-survey-reveals-85-all-jobs-filled-via-networking-lou-adler/)
    * [Meetup \| IBM Cloud Egypt](https://www.meetup.com/IBM-Cloud-Egypt/)
1. Job fairs and direct announcements.
1. [Wuzzuf search engine](https://wuzzuf.net/jobs/egypt); use the appropriate keywords, for example: "internship web", "internship machine learning", "internship computer vision", etc.

## International Internships

### Research Experience for Undergraduates (REU)

<blockquote class="twitter-tweet" data-lang="en"><p lang="en" dir="ltr">I&#39;ve seen several Tweets telling STEM undergrads to apply for REUs, but the replies are always filled with &quot;what&#39;s an REU?&quot; So, here&#39;s a thread about what REUs are, why you should consider applying, and how to find the right one for you:</p>&mdash; Celeste Labedz (@celestelabedz) <a href="https://twitter.com/celestelabedz/status/1083072664514646016?ref_src=twsrc%5Etfw">January 9, 2019</a></blockquote>


### Common Requirements

* Catchy resume.
    1. [Resumake](https://latexresu.me/): 
        * Resumake is a tool for automatically generating beautiful resumes.
        * You can export to LaTeX for further editing.
    1. \[[Your curriculum in LaTeX - part one](http://web.archive.org/web/20120111021524/http://stefano.italians.nl/archives/5)\]\[[part two](http://web.archive.org/web/20111127150043/http://stefano.italians.nl/archives/14)\] \[[part three ](http://web.archive.org/web/20120103055952/http://stefano.italians.nl/archives/26)\] \[[part four](http://web.archive.org/web/20120117043729/http://stefano.italians.nl/archives/50)\]
* Recommendation letters: all your teachers owe you a recommendation letter. Recommenders from diverse schools or places makes potential recommendation.
* Motivation letter: to reflect your strong reasons to apply for the internship. You should also convey your engineering skills and your research interests. General guidelines:
    * **Paragraph 1:** Introduce yourself and talk about some interesting milestones if you have.
    * **Paragraph 2-3:** Describe the general areas of research that interest you and why. Prove some interests by an overview of online courses, projects, or other internships in the field. Would be nice to add little philosophical views.
    * **Paragraph 4:** Tell us a little bit about yourself and your life experiences. Why do you feel you need that position?
    * The above elements are essential components in your letter. Try to avoid any elements to prevail on others, as much salt or no salt would make a bad recipe.
    * \[[Cover letter with style - part one ](http://web.archive.org/web/20120106084130/http://stefano.italians.nl/archives/55)\] \[[2](http://web.archive.org/web/20120106084426/http://stefano.italians.nl/archives/61)\] \[[3](http://web.archive.org/web/20120103000013/http://stefano.italians.nl/archives/62)\] \[[4](http://web.archive.org/web/20120103000017/http://stefano.italians.nl/archives/63)\] \[[5](http://web.archive.org/web/20120103000023/http://stefano.italians.nl/archives/64)\] \[[6](http://web.archive.org/web/20120103000109/http://stefano.italians.nl/archives/65)\]
* Grades: GPA (generally > 3.2)
* Rank (sometimes): top 5%
* English and GRE scores (sometimes)

### List of International Summer Schools

Domains: Biology, Biomedical, Medicine.

*Some links may be broken or outdates. If so, search with the program name in Google engine.*

* [IBP's database](https://pathwaystoscience.org/programs.aspx?adv=adv&fbclid=IwAR3R9srezOls_RGY6cR3El3vwICPElSUcyrGQuJISj3nDYs_lxs48grMhxU)
* [EPFL Lausanne (federal),](https://ic.epfl.ch/SummerAtEPFL)
* [Indeed Search Engine (Bioinformatics)](https://www.indeed.com/q-Bioinformatics-Intern-jobs.html)
* [California Institute of Technology ](http://www.surf.caltech.edu/)
* [ETH Zurich \| Student Summer Research Fellowship](https://www.inf.ethz.ch/studies/summer-research-fellowship.html)
* [University of Tokyo, Research Internship Programme ](https://www.ilo.k.u-tokyo.ac.jp/summer_en)
* http://www.lsm.bio.lmu.de/summer_school/
* [International Summer Science School Heidelberg](http://www.ish-heidelberg.de/)
* [Institute of Science and Technology Austria, ](https://ist.ac.at/research/internships/)
* [Okinawa Institute of Science and Technology, ](https://groups.oist.jp/grad/research-interns)
* [LSM International Summer Research Program, ](http://www.lsm.bio.lmu.de/summer_school/index.html)
* [University of Tokyo, Research Internship Programme ](http://www.s.u-tokyo.ac.jp/en/utrip/apply-now/)
* [Heidelberg University, HGS MathComp ](http://www.mathcomp.uni-heidelberg.de/index.php?id=212)
* Follow-up Google, IBM, Facebook, OpenAI students opportunities.
* [summer-2019-internships \| GitHub Repository](https://github.com/christine-hu/summer-2019-internships)
* [Open-Source-Internships \| GitHub Repository](https://github.com/tapaswenipathak/Open-Source-Internships)


## Research Interests

A suggested list for research interests that you may dedicate this summer to learn about.

* Artificial Intelligence and Machine Learning
* Data Science and Big Data
* High Performance Computing and Distributed Systems
* Bioinformatics
* Computational Neuroscience
* Algorithms Design and Theoretical Computer Science
* Security, Cryptography, and Blockchain
* Computer Architecture, Integrated Circuits Manufacturing, MEMS, NEMS
