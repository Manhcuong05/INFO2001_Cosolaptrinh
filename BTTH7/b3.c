#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Danh ba da day. Khong the them lien he moi.\n");
        return;
    }

    struct Contact newContact;

    printf("Nhap ten: ");
    scanf(" %[^\n]s", newContact.name);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]s", newContact.phone);
    printf("Nhap email: ");
    scanf(" %[^\n]s", newContact.email);

    contacts[numContacts++] = newContact;

    printf("Lien he da duoc them.\n");
}

void deleteContact() {
    char name[50];
    printf("Nhap ten lien he can xoa: ");
    scanf(" %[^\n]s", name);

    int i,found = 0;

    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contacts[i] = contacts[--numContacts];
            found = 1;
            printf("Lien he da duoc xoa.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay lien he co ten %s.\n", name);
    }
}

void searchContact() {
    char name[50];
    printf("Nhap ten lien he can tim: ");
    scanf(" %[^\n]s", name);

    int i,found = 0;

    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Thong tin lien he:\n");
            printf("Ten: %s\n", contacts[i].name);
            printf("So dien thoai: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay lien he co ten %s.\n", name);
    }
}

void updateContact() {
    char name[50];
    printf("Nhap ten lien he can cap nhat: ");
    scanf(" %[^\n]s", name);

    int i,found = 0;

    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Nhap ten: ");
            scanf(" %[^\n]s", contacts[i].name);
            printf("Nhap so dien thoai: ");
            scanf(" %[^\n]s", contacts[i].phone);
            printf("Nhap email: ");
            scanf(" %[^\n]s", contacts[i].email);
            found = 1;
            printf("Lien he da duoc cap nhat.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay lien he co ten %s.\n", name);
    }
}

void saveContactsToFile() {
    char filename[50];
    printf("Nhap ten file de luu danh ba: ");
    scanf(" %[^\n]s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    int i;

    for (i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("Danh ba da duoc luu vao file.\n");
}

void loadContactsFromFile() {
    char filename[50];
    printf("Nhap ten file de doc danh ba: ");
    scanf(" %[^\n]s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return 0;
    }

    numContacts = 0;

    while (fscanf(file, " %[^\n]s", contacts[numContacts].name) == 1) {
        fscanf(file, " %[^\n]s", contacts[numContacts].phone);
        fscanf(file, " %[^\n]s", contacts[numContacts].email);
        numContacts++;
    }

    fclose(file);
    printf("Danh ba da duoc tai tu file.\n");
}

void printMenu() {
    printf("\n----- Quan ly danh ba -----\n");
    printf("1. Them lien he\n");
    printf("2. Xoa lien he\n");
    printf("3. Tim kiem lien he\n");
    printf("4. Cap nhat lien he\n");
    printf("5. Luu danh ba vao file\n");
    printf("6. Tai danh ba tu file\n");
    printf("0. Thoat\n");
    printf("--------------------------\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                saveContactsToFile();
                break;
            case 6:
                loadContactsFromFile();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
