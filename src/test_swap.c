#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

void printList(t_list *lst) 
{
    while (lst != NULL) 
    {
        printf("%d ", *((int *)lst->content));
        lst = lst->next;
    }
    printf("\n");
}

int main() {
    // Test case 1: Swap single element list
    t_list *list1 = malloc(sizeof(t_list));
    int *data1 = malloc(sizeof(int));
    *data1 = 10;
    list1->content = data1;
    list1->next = NULL;
    printf("Before swap (single element list): ");
    printList(list1);
    ft_swap(&list1);
    printf("After swap (single element list): ");
    printList(list1);
    printf("\n");

    // Test case 2: Swap multiple element list
    t_list *list2 = malloc(sizeof(t_list));
    int *data2_1 = malloc(sizeof(int));
    int *data2_2 = malloc(sizeof(int));
    int *data2_3 = malloc(sizeof(int));
    *data2_1 = 20;
    *data2_2 = 30;
    *data2_3 = 40;
    list2->content = data2_1;
    list2->next = malloc(sizeof(t_list));
    list2->next->content = data2_2;
    list2->next->next = malloc(sizeof(t_list));
    list2->next->next->content = data2_3;
    list2->next->next->next = NULL;
    printf("Before swap (multiple element list): ");
    printList(list2);
    ft_swap(&list2);
    printf("After swap (multiple element list): ");
    printList(list2);
    printf("\n");

    // Test case 3: ss with single element lists
    t_list *list3a = malloc(sizeof(t_list));
    int *data3a = malloc(sizeof(int));
    *data3a = 50;
    list3a->content = data3a;
    list3a->next = NULL;
    t_list *list3b = malloc(sizeof(t_list));
    int *data3b = malloc(sizeof(int));
    *data3b = 60;
    list3b->content = data3b;
    list3b->next = NULL;
    printf("Before ss (single element lists): ");
    printList(list3a);
    printList(list3b);
    ss(&list3a, &list3b);
    printf("After ss (single element lists): ");
    printList(list3a);
    printList(list3b);
    printf("\n");

    // Test case 4: ss with multiple element lists
    t_list *list4a = malloc(sizeof(t_list));
    int *data4a_1 = malloc(sizeof(int));
    int *data4a_2 = malloc(sizeof(int));
    int *data4a_3 = malloc(sizeof(int));
    *data4a_1 = 70;
    *data4a_2 = 80;
    *data4a_3 = 90;
    list4a->content = data4a_1;
    list4a->next = malloc(sizeof(t_list));
    list4a->next->content = data4a_2;
    list4a->next->next = malloc(sizeof(t_list));
    list4a->next->next->content = data4a_3;
    list4a->next->next->next = NULL;
    t_list *list4b = malloc(sizeof(t_list));
    int *data4b_1 = malloc(sizeof(int));
    int *data4b_2 = malloc(sizeof(int));
    int *data4b_3 = malloc(sizeof(int));
    *data4b_1 = 100;
    *data4b_2 = 110;
    *data4b_3 = 120;
    list4b->content = data4b_1;
    list4b->next = malloc(sizeof(t_list));
    list4b->next->content = data4b_2;
    list4b->next->next = malloc(sizeof(t_list));
    list4b->next->next->content = data4b_3;
    list4b->next->next->next = NULL;
    printf("Before ss (multiple element lists):\n");
    printf("List A: ");
    printList(list4a);
    printf("List B: ");
    printList(list4b);
    ss(&list4a, &list4b);
    printf("After ss (multiple element lists):\n");
    printf("List A: ");
    printList(list4a);
    printf("List B: ");
    printList(list4b);
    printf("\n");

    // Free memory
    ft_lstclear(&list1, free);
    ft_lstclear(&list2, free);
    ft_lstclear(&list3a, free);
    ft_lstclear(&list3b, free);
    ft_lstclear(&list4a, free);
    ft_lstclear(&list4b, free);

    return 0;
}