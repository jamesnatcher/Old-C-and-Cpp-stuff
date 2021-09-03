
#include <stdio.h>
int main(int argc, char *  * argv) {
    int pete,jane, persons, apples /* , oranges */;
    printf("Enter an integer: "); 
    scanf("%d", &pete); 
    printf("Enter an integer: "); 
    scanf("%d", &jane);
    persons = pete;
    apples = jane;/* apples = oranges */                                
    while (persons != apples) { 
        if (persons > apples) {
			persons = persons - apples;
        }
        else {
            apples = apples - persons;
        }
    }
    printf("%d / %d = %d / %d\n", pete, jane, (pete /persons),((jane) / apples)); 
    return 0;
    }