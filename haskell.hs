import Data.Char (toLower)
import Data.List (sortBy)
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

main::IO()
main = do
    -- let str = "shibainu"
    -- let ans = no0 str

    -- let str = "パタトクカシーー"
    -- let ans = no1 str

    -- let strA = "パトカー"
    -- let strB = "タクシー"
    -- let ans = no2 strA strB

    let str = "Now I need a drink, alcoholic of course, after the heavy lectures involving quantum mechanics."
    let ans = no3 str


    putStrLn ans


