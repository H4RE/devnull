import Data.Array.Unboxed
import Data.List (sort)

-- abc361c
-- solve361::[Int]->[Int]->Int->[Int]
-- solve361 a b n
--     | n == 0 = a
--     | head b > last b = solve361 (tail a)  (tail b)  (n-1)
--     | otherwise = solve361 (init a) (init b) (n-1)

main::IO()
main = do

    ln1 <- getLine
    let [m,n] = map (read::String->Int) . words $ ln1

    ln2 <- getLine
    let a = sort . map (read::String->Int) . words $ ln2
    -- let a1 = zipWith (\i _ ->let xs = take (m-ni) (drop i a) in last xs - head xs) [0..ni] a
    let ua = listArray (0, length a - 1) a :: UArray Int Int


    let a1 = [ua ! (i + m - 1 - n) - ua ! i | i <- [0..n]]
    print $ minimum a1

    -- print a
    -- let diff = zipWith (-) (tail a) a
    -- print diff
    -- let s = solve361 a diff (n!!0)
    -- print $ last s - head s
