## Takeaways

### Jun-30-2025

- Solved the first 5 problems, they were pretty straightforward. 

- Use `printf`/`scanf` or `std::ios::sync_with_stdio(false);` and `std::cin.tie(null);`

- Use `long long int`! As long as it fits the memory limits

- `scanf` returns int, compiler will warn about it. Use other methods like a fixed buffer or cast into `(void)` and do nothing

- The spiral one was interesting, it boils down to implementing the rules in 4 cases, x>=y or not, one even or not.
- I had initially attempted to do it with linear algebra thinking it will be a nice function of f(x,y), something linear/polynomial with terms $\alpha \cdot x^2 + \beta \cdot xy + \gamma \cdot y^2 + \delta \cdot x + \epsilon \cdot y = \eta$ and do something like solve with Cramers rule the 5 equations and 5 variables. But this won't work because.. it's not a linear function, it's peicewise as seen here.
