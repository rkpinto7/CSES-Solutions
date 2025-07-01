## Takeaways

### Ju1-01-2025
- Solved the next 5 problems, they were fun

- I thought I'd need to pre-log and brute force the knights problem, but there's a nice formula by noting that knights can attack in 2x3 rectangles

- **[Two Sets]** I mostly played around with the numbers for two sets, noting numbers of type 3, 7, .. bascially all 1 less than multiples of 4 work and coded that but got wrong answer that even exact multiples of 4 work.

- This can be solved more rigorously. We know sum of n natural numbers is $\frac{n \cdot (n+1)}{2}$, we need to partition the numbers such that their sums are  $\frac{n \cdot (n+1)}{4}$

- This ends up being find solutions for $n \cdot (n+1) \equiv 0 \space (\text{mod 4})$, find which families of numbers satisfy it in $n \text{ mod } 4 \equiv 0$ ,  $n \text{ mod } 4 \equiv 1$, $n \text{ mod } 4 \equiv 2$ and  $n \text{ mod } 4 \equiv 3$, for those that do, investigate how the nums $1,2,..N$ can be divided into buckets (again by family of mod 4) for the final answer

- **[Bit Strings]** I was able to solve the binary exponentiation myself without having to look up the algorithm by drawing the tree myself for recursion

- **[Coin Piles]**  This is just linear algebra to solve $[a, b] - x[2, 1] - y[1, 2] = [0, 0]$, more like making sure x, y are whole numbers (0,1,2,..)

- **[Palindrome Reorder]** A classic problem you'd probably find on leetcode, the trick is simple, but I wanted to ensure I can do it fast. Looks like there's no real way to avoid output bottleneck or forming the output. Use the FastIO trick, the linter said use `nullptr` in `std::cin.tie(nullptr);`
 

### Jun-30-2025

- Solved the first 5 problems, they were pretty straightforward. 

- Use `printf`/`scanf` or `std::ios::sync_with_stdio(false);` and `std::cin.tie(null);`

- Use `long long int`! As long as it fits the memory limits

- `scanf` returns int, compiler will warn about it. Use other methods like a fixed buffer or cast into `(void)` and do nothing

- The spiral one was interesting, it boils down to implementing the rules in 4 cases, x>=y or not, one even or not.
- I had initially attempted to do it with linear algebra thinking it will be a nice function of f(x,y), something linear/polynomial with terms $\alpha \cdot x^2 + \beta \cdot xy + \gamma \cdot y^2 + \delta \cdot x + \epsilon \cdot y = \eta$ and do something like solve with Cramers rule the 5 equations and 5 variables. But this won't work because.. it's not a linear function, it's peicewise as seen here.
