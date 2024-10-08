import Data.Char (toLower)
import Data.List (sort, sortBy)
import Data.Ord (comparing)

import qualified Data.Map as Map
no0::String -> String
no0 [] = []
no0 (x:xs) = no0 xs ++ [x]

no1::String -> String
no1 x = [x !! 1] ++ [x !! 3] ++ [x !! 5] ++ [x !! 7]

no2::String -> String -> String
no2 xs ys = concat [[x,y]|(x,y)<-zip xs ys]

no3_0::String -> Map.Map Char Int
no3_0 = foldl count Map.empty
    where
        count m x = Map.insertWith (+) x 1 m

no3::String -> String
no3 = map fst . sortBy (comparing snd) . Map.toList . no3_0 . filter (`elem` ['a'..'z']) . map toLower

no4_1::String -> [String]
no4_1 = filter (not . null) . foldl split [""]
    where
        split acc char
            | isSplit char = acc ++ [""]
            | otherwise = init acc ++ [last acc ++ [char]]
        isSplit::Char -> Bool
        isSplit = (`elem` [' ', '.', ','])


no4 str = map fn $ zip [1..] (no4_1 str)
    where
        fn (f,s)
            |f `elem` [1, 5, 6, 7, 8, 9, 15, 16, 19] = take 1 s
            |otherwise = take 2 s

no5::Int -> String -> [String]
no5 n str
    | n > length strm = []
    | otherwise = zipWith (\i _ ->take n (drop i strm)) [0..length strm-n] strm
        where strm = filter (`elem` ['a'..'z']++['A'..'Z']) str

-- abc363c
solve::String -> Int -> Int
solve str n = length $ takeWhile (n>=) (scanl (+) 0 xs)
    where xs = sortBy (flip compare) $ map read $ words str ::[Int] 

main::IO()
main = do
    -- print $ scanl (+) 0 [1,2,3,4,5]

    ln <- getLine
    let ns = map read $ words ln ::[Int]


    lna <- getLine
    -- let a =sort $ map read $ words lna ::[Int]
    let ans1 = solve lna (ns!!1)

    lnb <- getLine
    let ans2 = solve lnb (ns!!2)

    print $ min (head ns) $ min ans1 ans2



    -- let str = "shibainu"
    -- let ans = no0 str

    -- let str = "パタトクカシーー"
    -- let ans = no1 str

    -- let strA = "パトカー"
    -- let strB = "タクシー"
    -- let ans = no2 strA strB

    -- let str = "Now I need a drink, alcoholic of course, after the heavy lectures involving quantum mechanics."
    -- let ans = no3 str

    -- let str = "Hi He Lied Because Boron Could Not Oxidize Fluorine. New Nations Might Also Sign Peace Security Clause. Arthur King Can."
    -- let ans = no4 str
    -- print ans
    
    -- let str = "I am an NLPer"
    -- let ans = no5 5 str
    -- print ans
    --
    -- putStrLn ans


