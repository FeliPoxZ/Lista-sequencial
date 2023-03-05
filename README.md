# Lista sequencial
## Nesse repositorio está demostrado um ADT de lista e sua implementação em lista sequencial (somente para inteiros)


- [Como usar](#como-usar)<br>
- [Criar lista](#criar-uma-lista)<br>
- [Liberar lista](#liberar-a-lista-da-memoria)<br>
- [Printar a lista](#printar-toda-a-lista)<br>
- [Adicionar um item a lista](#adicionar-um-item-a-lista)
- [Remover um item da lista](#remover-um-item-da-lista)
- [Modificar um item na lista](#modificar-um-item-na-lista)
- [Inserir um item na lista](#inserir-um-item-na-lista)



## Como usar:
<h3> Para utilizar o ADT basta: <br> <br>
Baixar o arquivo header "list.h" e o arquivo objeto "list.o" <br>
Incluir o "list.h" no seu arquivo "seu_arquivo.c" <br>
Gerar o arquivo objeto do seu arquivo "seu_arquivo.o" <br>
E compilar o seu arquivo objeto "seu_arquivo.o" junto com o arquivo "list.o" <br>
</h3>
<br>


### No seu código:

```cmd
> #include "list.h"
```

### No terminal:

```cmd
> gcc seu_arquivo.c -c
```




```cmd
> gcc seu_arquivo.o list.o -o list
```
"list" é apenas o nome do executável podendo ser qualquer nome 


## Criar uma lista
<h4>
Para criar uma lista basta voçê declarar uma variavel ponteiro do tipo List. <br>
</h4>
exemplo: <br>


```cmd
>  List *list;
```
- "list" (com letra minuscula) é apenas o nome da variavel podendo ser qualquer outro.

<h4>
Após declarar a variavel ponteiro basta chamar a função list_create()
</h4>


```cmd
>  list = list_create();
```
ou

```cmd
>  List *list = list_create();
```

- A função list_create não necessita de nenhum argumento e retorna um ponteiro do tipo List.


## Liberar a lista da memoria
<h4>
Para liberar uma lista basta voçê chamar a função list_free e passar como argumento a sua variavel ponteiro do tipo List. <br>
</h4>
<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:

```cmd
> list_free(list);
```

- list é so o nome da variavel substitua pelo nome da sua variavel.<br><br>
- A função list_free é uma função que necessita como argumento um ponteiro (ou variavel ponteiro) do tipo List e retorna um valor void (ou seja não retorna nada). <br><br>
- Sempre utilizada no fim do programa ou quando não irá mais utilizar a lista no programa.


## Printar toda a lista

<h4>
Para mostrar a lista basta chamar a função list_display e passar como argumento o seu ponteiro tipo List.
</h4>
<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:

```cmd
> list_display(list);
```
- list é so o nome da variavel substitua pelo nome da sua variavel.<br><br>
- A função list_display é uma função que necessita como argumento um ponteiro (ou variavel ponteiro) do tipo List e retorna um valor void (ou seja não retorna nada).


## Adicionar um item a lista
<h4>
Para adicionar um item a lista basta chamar a função list_add e passar como argumento o seu ponteiro tipo List, e o valor que deseja adicionar
</h4>
<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:

```cmd
> list_add(list, 7);
```
- list é só o nome da variavel substitua pelo nome da sua variavel.<br><br>
- E o numero 7 é apenas um exemplo podendo ser qualquer numero inteiro que voçe desejar.<br><br>
- A função list_add é uma função que necessita como argumento um ponteiro (ou variavel ponteiro) do tipo List e uma variavel do tipo inteiro (value) e retorna um valor nulo (ou seja não retorna nada).



## Remover um item da lista
<h4>
Para remover um item da lista basta criar uma variavel do tipo inteiro <br>
</h4>

exemplo:

```cmd
> int value;
```
value é só o nome da variavel podendo ser qualquer outro.<br>

<h4>
E chamar a função list_remove e passar como argumento o seu ponteiro tipo List, e o index do item que deseja remover
</h4>
<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:


```cmd
> value = list_remove(list, 5);
```
- list é só o nome da variavel substitua pelo nome da sua variavel.<br><br>
- E o numero 5 é apenas um exemplo podendo ser qualquer outro index (apenas numeros inteiros) que voçê desejar.<br><br>
- A função list_remove é uma função que necessita como argumento um ponteiro (ou variavel ponteiro) do tipo List e uma variavel do tipo inteiro (index) e retorna o valor que voçê removeu.


## Modificar um item na lista
<h4>
Para modificar um item que já está na lista basta chamar a função  list_set e passar como argumento o seu ponteiro tipo List, o index do item que deseja modificar, e o novo valor.
</h4>

<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:

```cmd
> list_set(list,1,3);
```
- list é só o nome da variavel substitua pelo nome da sua variavel.<br><br>
- E o numero 1 é apenas um exemplo podendo ser qualquer outro index (apenas numeros inteiros) que voçê desejar.<br><br>
- E o numero 3 é apenas um exemplo podendo ser qualquer numero inteiro que voçe desejar.<br><br>
- A função list_set é uma função que necessita como argumento um ponteiro (ou variavel ponteiro) do tipo List, uma variavel do tipo inteiro (index) e uma variavel do tipo inteiro (value) e retorna um valor nulo (ou seja não retorna nada). 

## Inserir um item na lista
<h4>
Para inserir um item no meio da lista sem perder os antigos valores basta chamar a função list_insert e passar como argumento o seu ponteiro tipo List, o index do item que deseja inserir, e o novo valor.
</h4>
<h5>
OBS: sem o ' * ' antes da variavel ponteiro.
</h5>

exemplo:

```cmd
> list_insert(list,2,17);
```
- list é só o nome da variavel substitua pelo nome da sua variavel.<br><br>
- E o numero 2 é apenas um exemplo podendo ser qualquer outro index (apenas numeros inteiros) que voçê desejar.<br><br>
- E o numero 17 é apenas um exemplo podendo ser qualquer numero inteiro que voçe desejar.<br><br>
