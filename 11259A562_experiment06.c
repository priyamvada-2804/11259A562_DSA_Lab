#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert an element into the priority queue
void insert(int value)
{
    if (size == MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    pq[size] = value;
    size++;

    printf("%d inserted successfully.\n", value);
}

// Find the minimum element
int findMin()
{
    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int min = pq[0];

    for (int i = 1; i < size; i++)
    {
        if (pq[i] < min)
            min = pq[i];
    }

    return min;
}

// Delete the minimum element
int deleteMin()
{
    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int minIndex = 0;

    // Find the index of the minimum element
    for (int i = 1; i < size; i++)
    {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    int min = pq[minIndex];

    // Remove the minimum element by shifting elements
    for (int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;

    return min;
}

// Display the priority queue
void display()
{
    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Insert\n");
        printf("2. Find Minimum\n");
        printf("3. Delete Minimum\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                value = findMin();

                if (size != 0)
                    printf("Minimum element = %d\n", value);
                break;

            case 3:
                value = deleteMin();

                if (size >= 0 && value != -1)
                    printf("Deleted minimum element = %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

