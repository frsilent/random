doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x > 100 then x else x*2
conanO'Brien = "It's a-me, Conan O'Brien!"

alwaysEven a b = let isEven x = if even x
                                then x
                                else x - 1
                in (isEven a, isEven b)

alwaysEven a b = (isEven a, isEven b)
  where isEven x = if even x then x else x -i
