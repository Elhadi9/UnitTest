#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function definitions from condState.c

struct node {
    int data;
    struct node *next;
};

struct node *createNewNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *insertAtFront(struct node *head, int data) {
    struct node *newNode = createNewNode(data);
    newNode->next = head;
    return newNode;
}

struct node *insertAtEnd(struct node *head, int data) {
    struct node *newNode = createNewNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return head;
}

struct node* insertAfter(struct node* head, int key, int newData) {
    struct node* curr = head;
    while (curr != NULL) {
        if (curr->data == key) {
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        return head;
    }
    struct node* newNode = createNewNode(newData);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

bool search(struct node* head, int x) {
    struct node* curr = head;
    while(curr != NULL) {
        if(curr->data == x) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

struct node *reverse(struct node *head) {
    struct node *curr = head, *prev = NULL, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int numOfNudes(struct node *head) {
    struct node *curr = head;
    int num = 0;
    while (curr != NULL) {
        curr = curr->next;
        num++;
    }
    return num;
}

void printList(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Test functions

void test_createNewNode(void) {
    struct node *n = createNewNode(10);
    CU_ASSERT_PTR_NOT_NULL(n);
    CU_ASSERT_EQUAL(n->data, 10);
    CU_ASSERT_PTR_NULL(n->next);
    free(n);
}

void test_insertAtFront(void) {
    struct node *head = createNewNode(1);
    head = insertAtFront(head, 2);
    CU_ASSERT_EQUAL(head->data, 2);
    CU_ASSERT_EQUAL(head->next->data, 1);
    free(head->next);
    free(head);
}

void test_insertAtEnd(void) {
    struct node *head = createNewNode(1);
    head = insertAtEnd(head, 2);
    CU_ASSERT_EQUAL(head->next->data, 2);
    free(head->next);
    free(head);
}

void test_insertAfter(void) {
    struct node *head = createNewNode(1);
    head->next = createNewNode(2);
    head = insertAfter(head, 1, 3);
    CU_ASSERT_EQUAL(head->next->data, 3);
    CU_ASSERT_EQUAL(head->next->next->data, 2);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_search(void) {
    struct node *head = createNewNode(1);
    head->next = createNewNode(2);
    CU_ASSERT_TRUE(search(head, 1));
    CU_ASSERT_TRUE(search(head, 2));
    CU_ASSERT_FALSE(search(head, 3));
    free(head->next);
    free(head);
}

void test_reverse(void) {
    struct node *head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head = reverse(head);
    CU_ASSERT_EQUAL(head->data, 3);
    CU_ASSERT_EQUAL(head->next->data, 2);
    CU_ASSERT_EQUAL(head->next->next->data, 1);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_numOfNudes(void) {
    struct node *head = createNewNode(1);
    head->next = createNewNode(2);
    CU_ASSERT_EQUAL(numOfNudes(head), 2);
    free(head->next);
    free(head);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("LinkedListTestSuite", 0, 0);

    CU_add_test(suite, "test_createNewNode", test_createNewNode);
    CU_add_test(suite, "test_insertAtFront", test_insertAtFront);
    CU_add_test(suite, "test_insertAtEnd", test_insertAtEnd);
    CU_add_test(suite, "test_insertAfter", test_insertAfter);
    CU_add_test(suite, "test_search", test_search);
    CU_add_test(suite, "test_reverse", test_reverse);
    CU_add_test(suite, "test_numOfNudes", test_numOfNudes);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
