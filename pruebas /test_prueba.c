#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"

void printList(t_list *lst) 
{
    while (lst) 
    {
        printf("%d ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("\n");
}

int main() {
    // Test case 1: Empty list
    t_list *list1 = NULL;
    printf("Before swap (empty list): ");
    printList(list1);
    ft_swap(&list1);
    printf("After swap (empty list): ");
    printList(list1);
    printf("\n");

    // Test case 2: Single element list
    t_list *list2 = malloc(sizeof(t_list));
    int *data2 = malloc(sizeof(int));
    *data2 = 10;
    list2->content = data2;
    list2->next = NULL;
    printf("Before swap (single element list): ");
    printList(list2);
    ft_swap(&list2);
    printf("After swap (single element list): ");
    printList(list2);
    printf("\n");

    // Test case 3: Multiple element list
    t_list *list3 = malloc(sizeof(t_list));
    int *data3_1 = malloc(sizeof(int));
    int *data3_2 = malloc(sizeof(int));
    *data3_1 = 20;
    *data3_2 = 30;
    list3->content = data3_1;
    list3->next = malloc(sizeof(t_list));
    list3->next->content = data3_2;
    list3->next->next = NULL;
    printf("Before swap (multiple element list): ");
    printList(list3);
    ft_swap(&list3);
    printf("After swap (multiple element list): ");
    printList(list3);
    printf("\n");

    return 0;
}