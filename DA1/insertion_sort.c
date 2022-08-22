#include <stdio.h>
#include <stdlib.h>

struct MobilePhone
{
    char modelname[20];
    int year;
    int camera_resolution;
    int RAM;
    int memory_card_size;
    char OS[20];
};

struct MobilePhone *create_mobilephone_array(int size)
{
    struct MobilePhone *mobilephone = (struct MobilePhone *)malloc(size * sizeof(struct MobilePhone));
    return mobilephone;
}

struct MobilePhone *input_mobilephones(int n)
{
    struct MobilePhone *mobilephones = create_mobilephone_array(n);
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("Enter modelname: ");
        scanf("%s", mobilephones[i].modelname);
        printf("Enter year: ");
        scanf("%d", &mobilephones[i].year);
        printf("Enter camera resolution: ");
        scanf("%d", &mobilephones[i].camera_resolution);
        printf("Enter RAM: ");
        scanf("%d", &mobilephones[i].RAM);
        printf("Enter memory card size: ");
        scanf("%d", &mobilephones[i].memory_card_size);
        printf("Enter OS: ");
        scanf("%s", mobilephones[i].OS);
    }
    return mobilephones;
}

void print_mobilephone(struct MobilePhone *mobilephone)
{
    printf("Modelname: %s\n", mobilephone->modelname);
    printf("Year: %d\n", mobilephone->year);
    printf("Camera resolution: %d\n", mobilephone->camera_resolution);
    printf("RAM: %d\n", mobilephone->RAM);
    printf("Memory card size: %d\n", mobilephone->memory_card_size);
    printf("OS: %s\n", mobilephone->OS);
}

void print_mobilephones_array(struct MobilePhone *mobilephones, int n)
{
    for (int i = 0; i < n; i++)
    {
        print_mobilephone(&mobilephones[i]);
    }
}

struct MobilePhone *insertion_sort_ram(struct MobilePhone *mobilephones)
{
    int n = sizeof(mobilephones) / sizeof(struct MobilePhone);
    for (int i = 1; i < n; i++)
    {
        struct MobilePhone key = mobilephones[i];
        int j = i - 1;
        while (j >= 0 && mobilephones[j].RAM > key.RAM)
        {
            mobilephones[j + 1] = mobilephones[j];
            j = j - 1;
        }
        mobilephones[j + 1] = key;
    }
    return mobilephones;
}

int main()
{
    int n;
    printf("Enter number of mobilephones: ");
    scanf("%d", &n);
    struct MobilePhone *mobilephones = input_mobilephones(n);
    printf("----------INPUT-----------\n");
    print_mobilephones_array(mobilephones, n);
    printf("--------------------------\n");
    struct MobilePhone *sorted_mobilephones = insertion_sort_ram(mobilephones);
    printf("----------SORTED-----------\n");
    print_mobilephones_array(sorted_mobilephones, n);
    printf("---------------------------\n");
    return 0;
}