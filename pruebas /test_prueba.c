#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"

 void printList(t_list *lst) 
{
    while (lst != NULL) 
    {
        printf("%d ", *((int *)lst->content));
        lst = (lst)->next;
    }
    printf("\n");

} 

int main() {

t_list *list4 = NULL;
printf("Before rotate (empty list): ");
printList(list4);
ft_re_rotate(&list4);
printf("After rotate (empty list): ");
printList(list4);
printf("\n");

// Test case 5: Rotate single element list
t_list *list5 = malloc(sizeof(t_list));
int *data5 = malloc(sizeof(int));
*data5 = 50;
list5->content = data5;
list5->next = NULL;
printf("Before rotate (single element list): ");
printList(list5);
ft_re_rotate(&list5);
printf("After rotate (single element list): ");
printList(list5);
printf("\n");

// Test case 6: Rotate multiple element list
t_list *list6 = malloc(sizeof(t_list));
int *data6_1 = malloc(sizeof(int));
int *data6_2 = malloc(sizeof(int));
int *data6_3 = malloc(sizeof(int));
int *data6_4 = malloc(sizeof(int));
*data6_1 = 60;
*data6_2 = 70;
*data6_3 = 80;
*data6_4 = 90;
list6->content = data6_1;
list6->next = malloc(sizeof(t_list));
list6->next->content = data6_2;
list6->next->next = malloc(sizeof(t_list));
list6->next->next->content = data6_3;
list6->next->next->next = malloc(sizeof(t_list));
list6->next->next->next->content = data6_4;
list6->next->next->next->next = NULL;
printf("Before rotate (multiple element list): ");
printList(list6);
ft_re_rotate(&list6);
printf("After rotate (multiple element list): ");
printList(list6);
printf("\n");

ft_lstclear(&list5,free);
ft_lstclear(&list6,free);
ft_lstclear(&list6,free);
}