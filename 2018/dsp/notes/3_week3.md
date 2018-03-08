---
layout: page
course: "sbe309"
category: "notes"
year: "2018"
title:  "Week 3: Euler's Identity, Sinusoids, and Fourier"
by: "Asem"
---

> These notes are inspired by  {% cite MDFTWEB07 %}

## Readings

* [Complex Numbers](https://ccrma.stanford.edu/~jos/mdft/Complex_Numbers.html)
* [Proof of Euler's Identity](https://ccrma.stanford.edu/~jos/mdft/Proof_Euler_s_Identity.html)
* [In-Phase & Quadrature Sinusoidal Components](https://ccrma.stanford.edu/~jos/mdft/In_Phase_Quadrature_Sinusoidal.html)
* [The DFT](https://ccrma.stanford.edu/~jos/mdft/DFT.html)
* [DFT matrix](https://ipfs.io/ipfs/QmXoypizjW3WknFiJnKLwHCnL72vedxjQkDDP1mXWo6uco/wiki/DFT_matrix.html)

## Euler's Identity

$$e^{j\theta} = \cos(\theta) + j\sin(\theta) \qquad\qquad \mbox{(Euler's Identity)}$$

### Properties of Exponents

$  a^{n_1} a^{n_2} = a^{n_1 + n_2} $

$  \left(a^{n_1}\right)^{n_2} = a^{n_1 n_2} $

### The Exponent Zero

$ a^0  a = a^0 a^1 = a^{0+1} = a^1 = a $

$ a^0  a = a $

$ {a^0 = 1.} $


### Negative Exponents

$ a^{-1} \cdot a = a^{-1} a^1 = a^{-1+1} = a^0 = 1. $

$ {a^{-1} = \frac{1}{a}.} $

$ {a^{-M} = \frac{1}{a^M}} $

### Rationale Exponents

A *rational* number is a real number that can be expressed as a ratio of two finite integers:

$$ \displaystyle x = \frac{L}{M}, \quad L\in\mathbb{Z},\quad M\in\mathbb{Z} $$

Applying property (2) of exponents, we have

$$ \displaystyle a^x = a^{L/M} = \left(a^{\frac{1}{M}}\right)^L. $$

Thus, the only thing new is $$ a^{1/M} $$ . Since

$$ \displaystyle \left(a^{\frac{1}{M}}\right)^M = a^{\frac{M}{M}} = a $$

we see that $$ a^{1/M}$$ is the $$ M$$ th root of $$ a $$ . This is sometimes written

$$  {a^{\frac{1}{M}} =  \sqrt[M]{a}.} $$

### e^(j theta)

We've now defined $ a^z$ for any positive real number $ a$ and any complex number $ z$ . Setting $ a=e$ and $ z=j\theta$ gives us the special case we need for Euler's identity. Since $ e^x$ is its own derivative, the Taylor series expansion for $ f(x)=e^x$ is one of the simplest imaginable infinite series: 

$$ e^x = \sum_{n=0}^\infty \frac{x^n}{n!} = 1 + x + \frac{x^2}{2} + \frac{x^3}{3!} + \cdots $$

The simplicity comes about because $ f^{(n)}(0)=1$ for all $ n$ and because we chose to expand about the point $ x=0$ . We of course define

$\displaystyle e^{j\theta} = \sum_{n=0}^\infty \frac{(j\theta)^n}{n!} = 1 + j\theta - \frac{\theta^2}{2} - j\frac{\theta^3}{3!} + \cdots \,. $ 

Note that all even-order terms are real while all odd-order terms are imaginary. Separating out the real and imaginary parts gives

$$ \mbox{Re} \big\{e^{j\theta}\big\} = 1 - \frac{\theta^2}{2} + \frac{\theta^4}{4!} - \cdots $$

$$ \mbox{Im} \big\{e^{j\theta}\big\} = \theta - \frac{\theta^3}{3!} + \frac{\theta^5}{5!} - \cdots\ $$

### Polar form

$\displaystyle z = r e^{j\theta} $ 

## In-Phase & Quadrature Sinusoidal Components

 From the trig identity $ \sin(A+B)=\sin(A)\cos(B)+\cos(A)\sin(B)$ , we have

$$ \begin{eqnarray*} x(t) &= & A \sin(\omega t + \phi) = A \sin(\phi + \omega t) \\ &=& \left[A \sin(\phi)\right] \cos(\omega t) + \left[A \cos(\phi)\right] \sin(\omega t) \\ &= & A_1 \cos(\omega t) + A_2 \sin(\omega t). \end{eqnarray*} $$

From this we may conclude that every sinusoid can be expressed as the sum of a sine function (phase zero) and a cosine function (phase $ \pi/2$ ). If the sine part is called the **in-phase** component, the cosine part can be called the **phase-quadrature** component. In general, **phase quadrature** means **90 degrees out of phase,** i.e., a relative phase shift of $ \pm\pi/2$.

It is also the case that every sum of an in-phase and quadrature component can be expressed as a single sinusoid at some amplitude and phase. The proof is obtained by working the previous derivation backwards.


## Complex Sinusoids in Frequency Domain

$\displaystyle x(t) = A_x e^{j\omega_x t} $ 

<img src="/gallery/img474.png" style="width:70%">

## Fourier Analysis

Fourier analysis is the process of decomposing a function into simple sinusoids known as basis functions.

$\displaystyle X(\omega_k) = \sum_{n=0}^{N-1}x(n) e^{-j\omega_k t_n} = \sum_{n=0}^{N-1}x(n) e^{-j 2\pi kn/N}, \quad k=0,1,2,\ldots N-1 $

$$ t_n = nT = \mbox{$n$th sampling instant (sec)} $$
$$ \omega_k =  k\Omega = \mbox{$k$th frequency sample (rad/sec)} $$
$$ T = 1/f_s = \mbox{time sampling interval (sec)} $$
$$ \Omega = 2\pi f_s/N = \mbox{frequency sampling interval (rad/sec)} $$


The transform *kernel*:

$\displaystyle e^{-j\omega_k t_n} = \cos(\omega_k t_n) - j \sin(\omega_k t_n) $ 

**Inner Product** = **Projection**

$ X(\omega_k)$ , the DFT at frequency $ \omega_k$ , is a measure of the amplitude and phase of the complex sinusoid which is present in the input signal $ x$ at that frequency.

### Signals: Vector View

A signal consists of $N $ samples, is equivalent to a two-dimensional vector. Each sample is a corrdinate in the N-dimensional space.

We already have that intuition when carrying signals in `Numpy` arrays, just as vectors.

### DFT not decomposing into sinusoids

**DFT** decompose singals up into complex exponentials.

## DFT Matrix

The transformation matrix W can be defined as 
$$ W = \left( \frac{\omega^{jk}}{ \sqrt{N} } \right )_{\{j,k=0,\ldots ,N-1\}} $$, 

or equivalently:

$$ {\displaystyle W={\begin{bmatrix}1&1&1&1&\cdots &1 \\ 1&\omega &\omega ^{2}&\omega ^{3}&\cdots &\omega ^{N-1} \\ 1&\omega ^{2}&\omega ^{4}&\omega ^{6}&\cdots &\omega ^{2(N-1)} \\ 1&\omega ^{3}&\omega ^{6}&\omega ^{9}&\cdots &\omega ^{3(N-1)}\\ \vdots &\vdots &\vdots &\vdots &\ddots &\vdots \\ 1&\omega ^{N-1}&\omega ^{2(N-1)}&\omega ^{3(N-1)}&\cdots &\omega ^{(N-1)(N-1)}\end{bmatrix}},} $$

where {\displaystyle \omega =e^{-2\pi i/N}}

<img src="/gallery/Fourierop_rows_only.svg" style="width:70%">

The following summarizes how the 8-point DFT works, row by row, in terms of fractional frequency:

* 0 measures how much DC is in the signal
* −1/8 measures how much of the signal has a fractional frequency of +1/8
* −1/4 measures how much of the signal has a fractional frequency of +1/4
* −3/8 measures how much of the signal has a fractional frequency of +3/8
* −1/2 measures how much of the signal has a fractional frequency of +1/2
* −5/8 measures how much of the signal has a fractional frequency of +5/8
* −3/4 measures how much of the signal has a fractional frequency of +3/4
* −7/8 measures how much of the signal has a fractional frequency of +7/8


### Examples

Two-point

The two-point DFT is a simple case, in which the first entry is the DC (sum) and the second entry is the AC (difference).

$$ \{\displaystyle {\begin{bmatrix}1 & 1 \\ 1 & -1 \end{bmatrix}}\} $$

The first row performs the sum, and the second row performs the difference.

The factor of $ 1/{\sqrt{2}} $ is to make the transform unitary (see below).
Four-point

The four-point DFT matrix is as follows:

$$  \displaystyle W={\begin{bmatrix}\omega^{0} & \omega^{0} & \omega^{0} & \omega^{0}\\ \omega^{0} & \omega^{1}&\omega^{2} & \omega^{3} \\ \omega^{0} & \omega^{2} & \omega^{0} & \omega^{2} \\ \omega^{0} & \omega^{3} & \omega^{2} & \omega^{1} \\ \end{bmatrix}} = { \begin{bmatrix} 1 & 1 & 1 & 1 \\ 1 & -i & -1 & i \\ 1 & -1 & 1 & -1 \\ 1 & i & -1 & -i \end{bmatrix}} $$

where $ \{\displaystyle \omega =e^{-{\frac {\pi i}{2}}}=-i\} $.
Eight-point

The first non-trivial integer power of two case is for eight points:

$$ \displaystyle W={\begin{bmatrix}\omega ^{0}&\omega ^{0}&\omega ^{0}&\omega ^{0}&\omega ^{0}&\omega ^{0}&\omega ^{0}&\omega ^{0} \\ \omega ^{0}&\omega ^{1}&\omega ^{2}&\omega ^{3}&\omega ^{4}&\omega ^{5}&\omega ^{6}&\omega ^{7} \\ \omega ^{0}&\omega ^{2}&\omega ^{4}&\omega ^{6}&\omega ^{0}&\omega ^{2}&\omega ^{4}&\omega ^{6} \\ \omega ^{0}&\omega ^{3}&\omega ^{6}&\omega ^{1}&\omega ^{4}&\omega ^{7}&\omega ^{2}&\omega ^{5}\\ \omega ^{0}&\omega ^{4}&\omega ^{0}&\omega ^{4}&\omega ^{0}&\omega ^{4}&\omega ^{0}&\omega ^{4} \\ \omega ^{0}&\omega ^{5}&\omega ^{2}&\omega ^{7}&\omega ^{4}&\omega ^{1}&\omega ^{6}&\omega ^{3}\\\omega ^{0}&\omega ^{6}&\omega ^{4}&\omega ^{2}&\omega ^{0}&\omega ^{6}&\omega ^{4}&\omega ^{2} \\ \omega ^{0}&\omega ^{7}&\omega ^{6}&\omega ^{5}&\omega ^{4}&\omega ^{3}&\omega ^{2}&\omega ^{1} \\ \end{bmatrix}}={\begin{bmatrix}1&1&1&1&1&1&1&1 \\ 1&\omega &-i&-i\omega &-1&-\omega &i&i\omega \\ 1&-i&-1&i&1&-i&-1&i \\ 1&-i\omega &i&\omega &-1&i\omega &-i&-\omega \\ 1&-1&1&-1&1&-1&1&-1 \\ 1&-\omega &-i&i\omega &-1&\omega &i&-i\omega \\ 1&i&-1&-i&1&i&-1&-i \\ 1&i\omega &i&-\omega &-1&-i\omega &-i&\omega \\ \end{bmatrix}}$$

where

$ \omega = e^{-{\frac{2\pi i}{8}}} = \frac{1}{\sqrt{2}} - \frac{i}{\sqrt{2}} $

(Note that $\omega^{8 + n} = \omega^{n}$.)

## References

1. Digital Signal Processing, **2nd Edition**, *Fundamentals and Applications*. Authors: Li Tan Jean Jiang.
2. Signals and Systems using MATLAB. by Luis Chaparro Ph.D. University of California Berkeley.
3. Mitra Digital Signale Processing, Computer Based Approach.
4. Oppenheim Discrete-Time Signal Processing.



## New Task: Writing Python/MATLAB Wrappers for C/C++

### Hints

* [Boost.Python](http://www.boost.org/doc/libs/1_66_0/libs/python/doc/html/index.html)
* [Wrapping C/C++ for Python](http://intermediate-and-advanced-software-carpentry.readthedocs.io/en/latest/c++-wrapping.html)
* [How to use C library in python? (Generating Python wrappers for C library)](http://karuppuswamy.com/wordpress/2012/01/28/how-to-use-c-library-in-python-generating-python-wrappers-for-c-library/)
* [Build MEX function from C/C++ or Fortran source code](https://www.mathworks.com/help/matlab/ref/mex.html?requestedDomain=true)

## Demo file

```bash
$ git clone https://github.com/sbme-tutorials/sbe309-week3-demo.git
```


## References

{% bibliography --cited %}
