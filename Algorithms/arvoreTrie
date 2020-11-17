class No:
    def __init__(self, chave=None, item=None, listaProx=[None]*10):
        self.item=item
        self.chave=chave
        self.listaProx=listaProx
class Indice:
    def __init__(self):
        self.root=No()

    def __getitem__(self, chave):
        findNo=self.root
        for char in chave:
            if findNo.listaProx[int(char)]==None:
                raise KeyError
            findNo=findNo.listaProx[int(char)]
            concatena=char
            if findNo.chave!=None:
                return findNo.listaProx[int(char)].item
            raise KeyError

    def __setitem__(self,chave,item):
        node=self.root

        for char in chave:
            if node.listaProx[int(char)]==None:
                node.listaProx[int(char)]=No(char)
                
            node=node.listaProx[int(char)]
            concatena=char
        node.listaProx[int(char)]=No(concatena, item)
        #node.item = item
            
