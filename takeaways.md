## Takeaways

### Sep-19-2025

**[Knight Moves Grid]** Inspired to solve this from reading https://lnkd.in/p/eVACNeGY It's a simple BFS problem from the source make the moves instead of doing it for every point backwards. BFS ensures a sort of diffusion from that point and everyone will get the lowest value. A similar thing could have been done with DFS and replacements if a smaller value is found, but there could be multiple rewrities making this inefficient. Also added in a quick optimization of `grid[nj][ni] = grid[ni][nj];` for good measure.


 
### Jul-02-2025

- Focused on the daily leetcode problem for the day [3333. Find the Original Typed String II](https://leetcode.com/problems/find-the-original-typed-string-ii/) and doe into generating functions. Apparently this is a basic introductory problem into this, and there are some CSES problems on this

- We need to find the strings in $\text{\textcolor{red}{aaa}\textcolor{blue}{bbb}\textcolor{green}{ccc}\textcolor{orange}{dd}\textcolor{red}{aa}\textcolor{blue}{b}\textcolor{green}{cc}}$ where you can delete characters but there should be atleast one character in the group.

- If Alice typed $\text{\textcolor{red}{aaa}\textcolor{blue}{bbb}}$

  - The run $\text{\textcolor{red}{aaa}}$ (length 3) could have been intended as: $\text{\textcolor{red}{a}}$ (length 1), $\text{\textcolor{red}{aa}}$ (length 2), or $\text{\textcolor{red}{aaa}}$ (length 3).

  - The run $\text{\textcolor{blue}{bbb}}$ (length 3) could have been intended as: $\text{\textcolor{blue}{b}}$ (length 1), $\text{\textcolor{blue}{bb}}$ (length 2), or $\text{\textcolor{blue}{bbb}}$ (length 3).
 
  - This can be represented as ${(\textcolor{red}{x^{1} + x^{2} + x^{3}}}) \cdot (\textcolor{blue}{x^{1} + x^{2} + x^{3}})= \textcolor{red}{x^1} \cdot \textcolor{blue}{x^1} +
\textcolor{red}{x^1} \cdot \textcolor{blue}{x^2} +
\textcolor{red}{x^1} \cdot \textcolor{blue}{x^3} +
\textcolor{red}{x^2} \cdot \textcolor{blue}{x^1} +
\textcolor{red}{x^2} \cdot \textcolor{blue}{x^2} +
\textcolor{red}{x^2} \cdot \textcolor{blue}{x^3} +
\textcolor{red}{x^3} \cdot \textcolor{blue}{x^1} +
\textcolor{red}{x^3} \cdot \textcolor{blue}{x^2} +
\textcolor{red}{x^3} \cdot \textcolor{blue}{x^3}$
  
      = $\displaystyle{x^2 + 2x^3 + 3x^4 + 2x^5 + x^6}$
 
    - The coefficient of $x^2$ is $1$. There is $1$ way to make a string of length $2$ ($\text{\textcolor{red}{a}\textcolor{blue}{b}}$).

    - The coefficient of $x^3$ is $2$. There are $2$ ways to make a string of length $3$ ($\text{\textcolor{red}{a}\textcolor{blue}{b}\textcolor{blue}{b}}, \text{\textcolor{red}{a}\textcolor{red}{a}\textcolor{blue}{b}}$).

    - The coefficient of $x^4$ is $3$. There are $3$ ways to make a string of length $4$ ($\text{\textcolor{red}{a}\textcolor{red}{a}\textcolor{blue}{b}\textcolor{blue}{b}}, \text{\textcolor{red}{a}\textcolor{blue}{b}\textcolor{blue}{b}\textcolor{blue}{b}}, \text{\textcolor{red}{a}\textcolor{red}{a}\textcolor{red}{a}\textcolor{blue}{b}}$).
   
  - For compact notation, we can represent coefficient of $x^j$ in a polynomal $F(x)$ as $[x^{j}] \space F(x)$
 
  - $[x^N]$ is the EXACT number of ways to form a string of length N.
 
  - From the original question, we want number of strings of length atleast k (k, k+1, k+2, ..), this means (number of strings of any length) - (number of strings of length < k)
      - If we split the original string $\text{\textcolor{red}{aaa}\textcolor{blue}{bbb}\textcolor{green}{ccc}\textcolor{orange}{dd}\textcolor{red}{aa}\textcolor{blue}{b}\textcolor{green}{cc}}$ into the run lengths groups $\text{freq} = [3, 3, 3, 2, 2, 1, 2]$
    
      -   (number of strings of any length) = $\prod_{i=0}^{n-1} \text{freq}_i$ (0 indexed, n is `len(freq)`)

Let's define `dp[i][j]` as the the number of ways to form a string of exactly length j, using only the first i runs from our `freq` array

$`f(i, j) = [x^{j}] \space \underbrace{(x^{1} + x^{2} + ... )}_{0^{th} \space \text{run}} \cdot \underbrace{(x^{1} + x^{2} + ... )}_{1^{st} \space \text{run}} \cdot \underbrace{(x^{1} + x^{2} + ... )}_{2^{nd} \space \text{run}} \cdot \dots \cdot \underbrace{(x^{1} + x^{2} + ... )}_{i^{th} \space \text{run}}`$ 

or even more compact, 

$${[x^{j}] \space (\prod_{p=0}^{i} (\sum_{q=1}^{\text{freq}[p]} x^q)})$$

A substructure for the dp can be found for $f(i, j)$ by separating the $i$-th term from the rest:

$`f(i, j) = [x^{j}] \left( \underbrace{\prod_{p=0}^{i-1} (\sum_{q=1}^{\text{freq}[p]} x^q)}_{\text{Polynomial for } f(i-1)} \right) \cdot \left( \underbrace{\sum_{\theta=1}^{\text{freq}[i]} x^\theta}_{\text{Polynomial for the } i\text{-th run}} \right)`$

This is the multiplication of two polynomials. The coefficient of $x^j$ in the product is the sum of products of coefficients whose exponents add up to $j$. Let's expand the polynomial for the $i$-th run:
$`(\textcolor{red}{x^1} + \textcolor{red}{x^2} + \dots + \textcolor{red}{x^{\text{freq}[i]}})`$

To obtain a final term of $x^j$, we can combine a term $x^\theta$ from the $i$-th run's polynomial with a term $x^{j-\theta}$ from the polynomial product of the first $i-1$ runs.

Let's consider each choice for $\theta$ from our new run:

- If we choose $\textcolor{red}{\theta=1}$ (term is $x^1$), we need a term of $x^{j-1}$ from the previous product. The number of ways to get this is, by definition, $f(i-1, j-1)$.
    
- If we choose $\textcolor{red}{\theta=2}$ (term is $x^2$), we need a term of $x^{j-2}$ from the previous product. The number of ways is $f(i-1, j-2)$.
    
- $\dots$
    
- If we choose $\textcolor{red}{\theta=\text{freq}[i]}$ (term is $x^{\text{freq}[i]}$), we need a term of $x^{j-\text{freq}[i]}$ from the previous product. The number of ways is $f(i-1, j-\text{freq}[i])$.


Since each choice of $\theta$ results in a distinct way to form a string of length $j$, we sum up the possibilities. This gives us our recurrence relation:

$f(i, j) = f(i-1, j-1) + f(i-1, j-2) + \dots + f(i-1, j-\text{freq}[i])$

This can be written more compactly using a summation:

$f(i, j) = \sum_{\theta=1}^{\text{freq}[i]} f(i-1, j-\theta)$


#### Calculating the Unwanted Strings and the Prefix Sum Optimization

Our DP recurrence gives us a way to compute the number of ways to form a string of any length $j$, after considering all the runs. Our very original goal was to subtract the number of strings of length less than k (Unwanted strings). If $N$ is the length of the run length array, $N-1$ is the index of the final run.

After finishing the DP calculations, the value $f(N-1, j)$ will hold the total number of ways to form a string of exactly length $j$.

Our goal is to find the total number of strings with length less than $k$. This is simply the sum of the counts for each length from $1$ to $k-1$:

$$ \text{Unwanted Strings} = \sum_{j=1}^{k-1} f(N-1, j) $$

We could compute the full DP table up to $f(N-1, k-1)$ and then sum the final row. However, the recurrence $f(i, j) = \sum_{\theta=1}^{\text{freq}[i]} f(i-1, j-\theta)$ is inefficient. If $\text{freq}[i]$ is large, this summation involves many terms, leading to a slow algorithm.

This is where we can be clever. The summation is over a contiguous block of indices of the previous state, $f(i-1, \dots)$. This structure is a perfect candidate for a **prefix sum optimization**.

We have $f(i, j) = \sum_{\theta=1}^{\text{freq}[i]} f(i-1, j-\theta)$

$$f(i, j) = f(i-1, j-1) + f(i-1, j-2) + \dots + f(i-1, j-\text{freq}[i])$$

Reversing the items, so that the index is increasing

$$f(i, j) = f(i-1, j-\text{freq}[i]) + f(i-1, j-\text{freq}[i] + 1) + \dots + f(i-1, j-1)$$



Let's define $P(i-1, m)$ as the prefix sum of the $(i-1)$-th state:

$$P(i-1, m) = \sum_{l=0}^{m} f(i-1, l)$$



A sum over a range can be expressed as the difference of two prefix sums. The sum of elements from index $a$ to $b$ is `(sum up to b) - (sum up to a-1)`. In our case:

 - The end of our range is at index $j-1$. The prefix sum up to this point is $P(i-1, j-1)$.
 - 
 - The start of our range is at index $j-\text{freq}[i]$. We need to subtract the part just before it, which is the prefix sum up to index $j-\text{freq}[i]-1$. This is $P(i-1, j-\text{freq}[i]-1)$.


This gives us our optimized recurrence:

$$f(i, j) = P(i-1, j-1) - P(i-1, j-\text{freq}[i]-1)$$

This is a massive improvement! We've replaced a summation that could be $O(k)$ with a single subtraction, which is $O(1)$. This brings the complexity of computing each new DP state down significantly in our quest to find $\sum_{j=1}^{k-1} f(N-1, j)$.



#### to be continued....


### Jul-01-2025
- Solved the next 6 problems, they were fun

- **[Two Knights]** I thought I'd need to pre-log and brute force the knights problem, but there's a nice formula by noting that knights can attack in 2x3 rectangles

- **[Two Sets]** I mostly played around with the numbers for two sets, noting numbers of type 3, 7, .. bascially all 1 less than multiples of 4 work and coded that but got wrong answer that even exact multiples of 4 work.

- This can be solved more rigorously. We know sum of n natural numbers is $\frac{n \cdot (n+1)}{2}$, we need to partition the numbers such that their sums are  $\frac{n \cdot (n+1)}{4}$

- This ends up being find solutions for $n \cdot (n+1) \equiv 0 \space (\text{mod 4})$, find which families of numbers satisfy it in $n \text{ mod } 4 \equiv 0$ ,  $n \text{ mod } 4 \equiv 1$, $n \text{ mod } 4 \equiv 2$ and  $n \text{ mod } 4 \equiv 3$, for those that do, investigate how the nums $1,2,..N$ can be divided into buckets (again by family of mod 4) for the final answer

- **[Bit Strings]** I was able to solve the binary exponentiation myself without having to look up the algorithm by drawing the tree myself for recursion

-  **[Trailing Zeros]** I remember doing things like this back in 2014, I drew out and recalled the exact way, see how to obtain 2's and 5's in the factorial. 2's are abundant, 5 determines everything and we can do $⌊\frac{N}{5}⌋ + ⌊\frac{N}{5^{2}}⌋ + ⌊\frac{N}{5^{3}}⌋ + ...  $

- **[Coin Piles]**  This is just linear algebra to solve $[a, b] - x[2, 1] - y[1, 2] = [0, 0]$, more like making sure x, y are whole numbers (0,1,2,..)

- **[Palindrome Reorder]** A classic problem you'd probably find on leetcode, the trick is simple, but I wanted to ensure I can do it fast. Looks like there's no real way to avoid output bottleneck or forming the output. Use the FastIO trick, the linter said use `nullptr` in `std::cin.tie(nullptr);`
 

### Jun-30-2025

- Solved the first 5 problems, they were pretty straightforward. 

- Use `printf`/`scanf` or `std::ios::sync_with_stdio(false);` and `std::cin.tie(null);`

- Use `long long int`! As long as it fits the memory limits

- `scanf` returns int, compiler will warn about it. Use other methods like a fixed buffer or cast into `(void)` and do nothing

- The spiral one was interesting, it boils down to implementing the rules in 4 cases, x>=y or not, one even or not.
- I had initially attempted to do it with linear algebra thinking it will be a nice function of f(x,y), something linear/polynomial with terms $\alpha \cdot x^2 + \beta \cdot xy + \gamma \cdot y^2 + \delta \cdot x + \epsilon \cdot y = \eta$ and do something like solve with Cramers rule the 5 equations and 5 variables. But this won't work because.. it's not a linear function, it's peicewise as seen here.
