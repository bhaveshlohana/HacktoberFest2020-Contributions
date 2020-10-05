class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
     
class Stack:
    def __init__(self):
        self.top = None
        # atributos que comecam com _ no python significa que eh um atributo que nao deve ser manipualdo diretamente
        self._size = 0

    def __len__(self):
        '''Retorna o tamanho da pilha
            Complexidade O(1)'''
        return self._size

    def push(self, elem):
        '''Insere um elemento na pilha
            Complexidade O(1)'''
        node = Node(elem)
        node.next = self.top
        self.top = node
        self._size += 1

    def pop(self):
        '''Remove o elemento do topo da pilha
            Complexidade O(1)'''
        if self._size > 0:
            node = self.top
            self.top = self.top.next
            self._size -= 1
            return node.data
        raise IndexError('The stack is empty')


    def pick(self):
        '''Retorna o elemento do topo da pilha (sem remover)
            Complexidade O(1)'''
        if self._size > 0:
            return self.top.data

    def __repr__(self):
        '''Retorna todos os elementos da pilha
            Complexidade O(n)'''
        r = ''
        pointer = self.top
        while pointer:
            r = r + str(pointer.data) + '\n'
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()
