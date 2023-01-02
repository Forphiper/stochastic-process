# Stochastic Process

Run simulations of the following scenarios: 
* Problem1: The Gambler Problem
    * Initially we have 50 dollars
    * Each round, there's probability k to get 1 dollar and probability 1 - k to lose 1 dollar
    * Continue until we hit 100 dollars or 0 dollar. We care about how the change of k impacts the resutls
* Problem2: Points Around the Circle
    * There are n+1 points around the circle, that is, point 0 to n
    * Start from point 0
    * Each round, there's probability 0.5 to go to the left point(counterclockwise) and probability 0.5 to go to the right point(clockwise)
    * Continue until all the points are visited, and we care about the last point we visit. What are their chances respectively?
* Problem3: Brownian Motion
    * Initially we are at 0 on the line
    * Cut the time into many small pieces, let time frame = delta_t
    * Each time frame we take one step, and every step follows normal distribution. That is, assume each step = X, X~Normal(0, delta_t)
    * For example, the step may be 0.1 or -0.05
    * Continue until we hit A or -B, where A, B are positive integer
    * We care about the chance of go up A and the chance of go down B
