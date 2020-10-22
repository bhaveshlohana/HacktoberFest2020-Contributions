{-
- Encontra o ultimo elemento de uma lista. Caso a lista seja vazia retorne o seguinte comando: error "Lista vazia!" 
-}
meuLast [] = error "Lista vazia!"
meuLast xs = meuLast $ tail xs


{-
- Encontra o penultimo elemento de uma lista. Caso a lista seja vazia ou tenha apenas um elemento retorne o seguinte comando: error "Lista sem penultimo" 
-}

penultimo [] = error "Lista sem penultimo"    
penultimo (penult: ultimo : [] ) = penult
penultimo xs = penultimo $ tail xs

{-
- Retorna o k-esimo (k varia de 1 ate N) elemento de uma lista. Ex: elementAt 2 [4,7,1,9] = 7
-}
elementAt _ [] = undefined
elementAt 1 (h:t) = h
elementAt i xs = elementAt (i-1) (tail xs)

{-
- Retorna o tamanho de uma lista. 
-}
meuLength [] = 0
meuLength xs = 1 + meuLength (tail xs) 

{-
- Retorna o inverso de uma lista. 
-}
meuReverso (x:xs) = meuReverso xs ++ [x]


{-
- Diz se uma lista é palindrome. 
-}
isPalindrome xs = xs == reverse xs

{-c
- Remove os elementos duplicados de uma lista. Ex: compress [2,5,8,2,1,8] = [2,5,8,1]
- Voce pode usar a funcao elem de Haskell
-}
compress xs = auxCompress [] xs

auxCompress acumulador [] = acumulador

auxCompress acumulador (h:t) 
    | h `elem` acumulador = (auxCompress  acumulador t)
    | otherwise = (auxCompress (acumulador ++ [h]) t)
{-
- Varre a lista da esquerda para a direita e junta os elementos iguais. Ex: compact [2,5,8,2,1,8] = [2,2,5,8,8,1]
- Voce pode usar funcoes sobre listas como : (cons), filter, etc.
-}
-- compact xs = ???


{-
- Retorna uma lista de pares com os elementos e suas quantidades. Ex: encode [2,2,2,3,4,2,5,2,4,5] = [(2,5),(3,1),(4,2),(5,2)]
- Voce pode usar funcoes sobre listas como : (cons), filter, etc.
-}
encode (h:t) = [h]

{-
- Divide uma lista em duas sublistas onde o ponto de divisao é dado. Ex: split [3,6,1,9,4] 3 = [[3,6,1],[9,4]]
-}


split xs i = [ select xs i, reverse $ select (reverse xs) (length xs - i)]
select xs 0 = []
select (h:t) i = h : (select t (i-1))

{-
- Extrai um pedaço (slice) de uma lista especificado por um intervalo. 
- Ex: slice [3,6,1,9,4] 2 4 = [6,1,9]
-}

slice xs 1 imax = head $ split xs imax
slice xs imin imax = slice (tail xs) (imin - 1) (imax -1)

{-
- Insere um elemento em uma posicao especifica de uma lista. 
- Ex: insertAt 7 4 [3,6,1,9,4] = [3,6,1,7,9,4]
-}
insertAt el 1 (h:t) = el : h : t
insertAt el pos (h:t) = h: (insertAt el (pos - 1) t)

{-
- Ordena uma lista em ordem crescente. Voce deve seguir a ideia do selectionsort onde os elementos 
- menores sao trazidos para o inicio da lista um a um. Esta funcao ja esta implementada.
-}
minList [x] = x
minList (x:xs) = if (x < (minList xs)) then x else minList xs

remove e (x:xs) | e == x = xs
                | otherwise = x:(remove e xs)
sort [] = []
sort xs = x:ys 
    where
        x = minList xs
        ys = sort (remove x xs) 

{-
- Calcula a soma de todos os elementos de uma lista usando foldr.
-}
mySum xs = foldr (+) 0  xs

{-
- Dada a funcao max que retorna o maximo entre dois numeros, escreva uma funcao que usa a função
- foldr e max para retornar o maximo de uma lista se a lista não é vazia.
-}
maxList (h:t) = foldr (max) h t

{-
- Transforma uma string em uma palindrome acrescentando o reverso da string ao seu final sem usar a funcao reverse. 
- Ex: buildPalindrome [1,2,3] = [1,2,3,3,2,1]. 
-}
buildPalindrome xs = xs ++ percorreDeTrasParaFrente xs
percorreDeTrasParaFrente [] = []
percorreDeTrasParaFrente xs = (last xs) : percorreDeTrasParaFrente (init xs)
{-
- Computa a media dos elementos de uma lista de numeros, sem usar nenhuma funcao pronta de listas.
-}
mean [] = 0
mean xs = (media xs 0 0)


media [] 0 soma = undefined 
media [] index soma = soma `div` index 
media (h:t) index soma = media t (index + 1) (soma + h)

{-
- Escreva a funcao myAppend que faz o append de uma lista xs com a lista ys, usando a função foldr. 
-}
myAppend xs ys = foldr (:) xs ys