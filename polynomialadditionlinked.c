#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int coeff;
int exp;
struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->coeff = coeff;
newNode->exp = exp;
newNode->next = NULL;
return newNode;
}

void insertTerm(Node** poly, int coeff, int exp) {
Node* newNode = createNode(coeff, exp);
if (*poly == NULL || (*poly)->exp < exp) {
newNode->next = *poly;
*poly = newNode;
} else {
Node* temp = *poly;
while (temp->next != NULL && temp->next->exp > exp)
temp = temp->next;
if (temp->exp == exp) {
temp->coeff += coeff;
} else if (temp->next != NULL && temp->next->exp == exp) {
temp->next->coeff += coeff;
} else {
newNode->next = temp->next;
temp->next = newNode;

}
}
}

Node* addPolynomials(Node* poly1, Node* poly2) {
Node* result = NULL;
while (poly1 != NULL && poly2 != NULL) {
if (poly1->exp > poly2->exp) {
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
} else if (poly1->exp < poly2->exp) {
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
} else {
int sum = poly1->coeff + poly2->coeff;
if (sum != 0)
insertTerm(&result, sum, poly1->exp);
poly1 = poly1->next;
poly2 = poly2->next;
}
}

while (poly1 != NULL) {
insertTerm(&result, poly1->coeff, poly1->exp);
poly1 = poly1->next;
}
while (poly2 != NULL) {
insertTerm(&result, poly2->coeff, poly2->exp);
poly2 = poly2->next;
}
return result;
}


void displayPolynomial(Node* poly) {
if (poly == NULL) {
printf("0\n");
return;
}
while (poly != NULL) {
printf("%dx^%d", poly->coeff, poly->exp);
poly = poly->next;
if (poly != NULL)
printf(" + ");
}
printf("\n");
}

void inputPolynomial(Node** poly, int num) {
int coeff, exp;
printf("Enter terms for Polynomial %d (coeff exp):\n", num);
int n;
printf("Enter number of terms: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Term %d - Coefficient: ", i + 1);
scanf("%d", &coeff);
printf("Term %d - Exponent: ", i + 1);
scanf("%d", &exp);
insertTerm(poly, coeff, exp);
}
}

int main() {
Node* poly1 = NULL;
Node* poly2 = NULL;

printf("=== Polynomial Addition ===\n");

inputPolynomial(&poly1, 1);
inputPolynomial(&poly2, 2);

printf("\nPolynomial 1: ");
displayPolynomial(poly1);

printf("Polynomial 2: ");
displayPolynomial(poly2);
Node* result = addPolynomials(poly1, poly2);

printf("Sum: ");
displayPolynomial(result);

return 0;
}