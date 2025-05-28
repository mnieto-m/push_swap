#include "push_swap.h"

t_list  *ft_lstcopy_new(t_list *lst)
{
    t_list  *new_list;
    void    *content_copy;

    if (!lst)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        // Asume que el contenido es un int* (ajusta según tu caso)
        content_copy = malloc(sizeof(int));  
        if (!content_copy)
            return (NULL);  // Manejo de error (libera lo ya copiado)
        *(int *)content_copy = *(int *)lst->content;  // Copia el valor
        ft_lstadd_back(&new_list, ft_lstnew(content_copy));
        lst = lst->next;
    }
    return (new_list);
}