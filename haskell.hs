no0::String -> String
no0 [] = []
no0 (x:xs) = no0 xs ++ [x]

no1::String -> String
no1 x = [x !! 1] ++ [x !! 3] ++ [x !! 5] ++ [x !! 7]

no2::String -> String -> String
no2 xs ys = concat [[x,y]|(x,y)<-zip xs ys]


main::IO()
main = do
    -- let str = "shibainu"
    -- let ans = no0 str

    -- let str = "パタトクカシーー"
    -- let ans = no1 str

    let strA = "パトカー"
    let strB = "タクシー"
    let ans = no2 strA strB


    putStrLn ans


