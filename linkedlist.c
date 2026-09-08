#include <stdio.h>

#define MAX_NODES 50

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node nodePool[MAX_NODES];
int nodeCount = 0;

struct Node* createNode(int coeff, int exp) {
    if (nodeCount >= MAX_NODES) {
        printf("Node pool exhausted!\n");
        return NULL;
    }
    struct Node* newNode = &nodePool[nodeCount++];
    (*newNode).coeff = coeff;
    (*newNode).exp = exp;
    (*newNode).next = NULL;
    return newNode;
}


void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (newNode == NULL) return; 

    if (*head == NULL || exp > (*head)->exp) {
        (*newNode).next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while ((*temp).next != NULL && (*(*temp).next).exp > exp) {
            temp = (*temp).next;
        }
        (*newNode).next = (*temp).next;
        (*temp).next = newNode;
    }
}


void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", (*temp).coeff, (*temp).exp);
        temp = (*temp).next;
        if (temp != NULL) printf(" + ");
    }
    printf("\n");
}


struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* resultHead = NULL;
    struct Node* resultTail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct Node* newNode = NULL;
        if ((*poly1).exp > (*poly2).exp) {
            newNode = createNode((*poly1).coeff, (*poly1).exp);
            poly1 = (*poly1).next;
        } else if ((*poly2).exp > (*poly1).exp) {
            newNode = createNode((*poly2).coeff, (*poly2).exp);
            poly2 = (*poly2).next;
        } else {
            int sum_coeff = (*poly1).coeff + (*poly2).coeff;
            if (sum_coeff != 0) {
                newNode = createNode(sum_coeff, (*poly1).exp);
            }
            poly1 = (*poly1).next;
            poly2 = (*poly2).next;
        }

        if (newNode != NULL) {
            if (resultHead == NULL) {
                resultHead = resultTail = newNode;
            } else {
                (*resultTail).next = newNode;
                resultTail = newNode;
            }
        }
    }

    while (poly1 != NULL) {
        struct Node* newNode = createNode((*poly1).coeff, (*poly1).exp);
        if (resultTail != NULL) {
            (*resultTail).next = newNode;
            resultTail = newNode;
        } else {
            resultHead = resultTail = newNode;
        }
        poly1 = (*poly1).next;
    }

    while (poly2 != NULL) {
        struct Node* newNode = createNode((*poly2).coeff, (*poly2).exp);
        if (resultTail != NULL) {
            (*resultTail).next = newNode;
            resultTail = newNode;
        } else {
            resultHead = resultTail = newNode;
        }
        poly2 = (*poly2).next;
    }

    return resultHead;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;


    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, -3, 2);
    insertTerm(&poly2, 8, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum         : ");
    displayPolynomial(sum);

    return 0;
}
