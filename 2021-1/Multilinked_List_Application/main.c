
#include "MultiLinked_List.h"

int main(void)
{
    int result;
    char cmd;
    HeadNode* headnode = createHead();
    DataNode* tmpnode = createNode();
    DataNode* newnode;

    printf("***** Start Program *****\n\n");
    do {
        printf("\n===== Command List =====");
        printf("\nP: Print Data\n");
        printf("S: Search Data\n");
        printf("I: Insert Data\n");
        printf("D: Delete Data\n");
        printf("Q: Quit Program\n\n");
        
        printf("Input command: ");
        scanf(" %c", &cmd);


        switch (cmd) {
            case 'P':
            {
                printAll(headnode);

                break;
            }
            case 'S':
            {
                char key;
                printf("Select key(Year-y/Title-t/Director-d): ");
                scanf(" %c", &key);
                if (key == 'y') {
                    int tmpyear;
                    printf("Input year: ");
                    scanf(" %d", &tmpyear);
                    tmpnode->movie->year = tmpyear;
                }
                else if (key == 't') {
                    char tmptitle[41];
                    printf("Input title: ");
                    scanf(" %s", tmptitle);
                    strcpy(tmpnode->movie->title, tmptitle);
                }
                else if (key == 'd') {
                    char tmpdirector[41];
                    printf("Input director: ");
                    scanf(" %s", tmpdirector);
                    strcpy(tmpnode->movie->director, tmpdirector);
                }
                printf("\n\n");
                search(tmpnode, headnode, key);

                break;
            }
            case 'I':
            {
                newnode = scanNode();
                insert(newnode, headnode);

                break;
            }
            case 'D':
            {
                
                char key;
                printf("Select key(Year-y/Title-t/Director-d): ");
                scanf(" %c", &key);
                if (key == 'y') {
                    int tmpyear;
                    printf("Input year: ");
                    scanf(" %d", &tmpyear);
                    tmpnode->movie->year = tmpyear;
                }
                else if (key == 't') {
                    char tmptitle[41];
                    printf("Input title: ");
                    scanf(" %s", tmptitle);
                    strcpy(tmpnode->movie->title, tmptitle);
                }
                else if (key == 'd') {
                    char tmpdirector[41];
                    printf("Input director: ");
                    scanf(" %s", tmpdirector);
                    strcpy(tmpnode->movie->director, tmpdirector);
                }

                delete(tmpnode, headnode, key);

                break;
            }
            case 'Q':
            {
                printf("\n\n***** End Program *****\n");
                free(tmpnode);
                free(headnode);

                return 0; // 프로그램 종료
            }
            default:
            {
                printf("Wrong command\n");

                break;
            }
        }

    } while (cmd != 'Q');

}
