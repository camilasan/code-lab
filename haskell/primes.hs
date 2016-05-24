numbers = [4..6000]

--primes = [x | x <- a, x `mod` 2 /= 0, x `mod` 3 /= 0, x `mod` 4 /= 0, x `mod` 5 /= 0, x `mod` 6 /= 0]
--loop array func = map func array
--primes = loop [4..200] $ \i -> map(
--foo(x, y) = (x `mod` y)
--call the map func to validate the prime

func(x) = x `mod` numbers

primes = [y | y <- numbers, func(y) /= 0, y /= numbers]

main = print primes