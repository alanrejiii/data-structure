#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

typedef struct Node {
char url[MAX_URL_LENGTH];
struct Node* prev;
struct Node* next;
} Node;

Node* current = NULL;

void visitNewPage(const char* url) {
Node* newNode = (Node*)malloc(sizeof(Node));
strcpy(newNode->url, url);
newNode->prev = current;
newNode->next = NULL;

if (current != NULL) {
if (current->next != NULL) {
Node* temp = current->next;
while (temp != NULL) {
Node* toDelete = temp;
temp = temp->next;
free(toDelete);
}
}
current->next = newNode;
}

current = newNode;
printf("Visited: %s\n", current->url);
}

void goBack() {
if (current == NULL || current->prev == NULL) {
printf("No previous page.\n");
return;
}
current = current->prev;
printf("Went back to: %s\n", current->url);
}

void goForward() {
if (current == NULL || current->next == NULL) {
printf("No next page.\n");
return;
}
current = current->next;
printf("Went forward to: %s\n", current->url);
}

void showCurrentPage() {
if (current)
printf("Current page: %s\n", current->url);
else
printf("No page visited yet.\n");
}

void freeHistory() {

while (current && current->prev != NULL)
current = current->prev;

while (current != NULL) {
Node* temp = current;

current = current->next;
free(temp);
}
}

int main() {
int choice;
char url[MAX_URL_LENGTH];

while (1) {
printf("\n--- Browser Navigation ---\n");
printf("1. Visit new page\n");
printf("2. Go back\n");
printf("3. Go forward\n");
printf("4. Show current page\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar();
switch (choice) {
case 1:
printf("Enter URL: ");
fgets(url, MAX_URL_LENGTH, stdin);
url[strcspn(url, "\n")] = '\0';
visitNewPage(url);
break;
case 2:
goBack();
break;
case 3:
goForward();
break;
case 4:
showCurrentPage();
break;

case 5:
freeHistory();
printf("Exiting browser.\n");
return 0;
default:
printf("Invalid choice. Try again.\n");
}
}

return 0;
}