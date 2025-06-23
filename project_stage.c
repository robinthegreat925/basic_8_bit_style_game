#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//#ROBIN IN THE WOODS
int progress = 1;
struct player {
    int x;
    int y;
    char health[5];
    char money[10];
} p = {1, 1, {'*', '*', '*', '*', '*'}, {}};

struct enemy {
    int x;
    int y;
    int health;
    char symbol;
    char moves[10];
    int current_move;
};

struct enemy enemies[10] = {
    {5, 5, 3, 'Z', {'w', 'a', 's', 'd'}, 0},
    {10, 10, 2, 'X', {'d', 's', 'a', 'w'}, 0}
};

int top = 4;
int topm = -1;
char **stage();
void print(char **stage);
void moveplayer(char **stage, char move);
void moveenemies(char **stage);
void stage_clear(char **stage);

int main() 
{
    char **st = stage();
    while (progress) 
    {
        system("cls");

        if ((p.x == 38) && (p.y == 2) && (progress >= 1)) 
        {
            printf("Stage Complete:\n");
            progress++;
            stage_clear(st);
            st = stage();
        }
        printf("move:w/a/s/d    quit:q\n");

        if (top == -1) 
        {
            printf("GAME OVER:");
            return 0;
        }

        if (topm == 15) 
        {
            printf("Stage Complete:\n");
            progress++;
            stage_clear(st);
            st = stage();
        }

        printf("Money:");
        for (int i = 0; i <= topm; i++) 
        {
            printf("%c", p.money[i]);
        }
        printf("\n");

        printf("health: ");
        for (int i = 0; i < top + 1; i++) 
        {
            printf("%c ", p.health[i]);
        }
        printf("\n");
        fflush(stdin);

        print(st);

        char move = getch();
        if (move == 'q' || move == 'Q') 
        {
            printf("Quitting:\n");
            return 0;
        }

        moveplayer(st, move);
        moveenemies(st); 
    }
}

void print(char **stage) 
{
    for (int i = 0; i < 16; i++) 
    {
        for (int j = 0; j < 39; j++) 
        {
            printf("%c", stage[i][j]);
        }
        printf("\n");
    }
}

char **stage() 
{
    char **stages = (char **)malloc(16 * sizeof(char*));
    for (int i = 0; i < 16; i++) 
    {
        stages[i] = (char*)malloc(39 * sizeof(char));
    }
    switch (progress) 
    {
        case 1: 
        {
            char sta[16][40] = 
            {
                "* * * * * * * * * * * * * * * * * * * *",
                "* s *                                 *",
                "*   *          $       #              E", 
                "*                                     *",   
                "*     #   *********************       *",    
                "*                   *                 *",    
                "*                   *            #$   *",
                "*              $    *                 *",
                "*                   *                 *",
                "*      #            *                 *",
                "*                  $*                 *",
                "*         *********************       *",
                "*                                     *",
                "* $ #                         #       *",
                "*                                     *",
                "***************************************",
            };
            p.x = 1;
            p.y = 1;
            for (int i = 0; i < 16; i++) 
            {
                for (int j = 0; j < 39; j++) 
                {
                    stages[i][j] = sta[i][j];
                }
            }
            return stages;
            break;
        }

        case 2: 
        {
            char sta[16][40] = 
            {
                "* * * * * * * * * * * * * * * * * * * *",
                "* s *                                 *",
                "*   *                  #         #    E", 
                "*                                #  $ *",   
                "*     #   *********************  #    *",    
                "*######             *     $      #    *",    
                "*    $#             *   #        #    *",
                "* #####        $    *   #             *",
                "*                   *####             *",
                "*      #            * $ #             *",
                "*                  $*   #             *",
                "*         *********************       *",
                "***###                                *",
                "***###                                *",
                "******                                *",
                "***************************************",
            };
            p.x = 1;
            p.y = 1;
            for (int i = 0; i < 16; i++) 
            {
                for (int j = 0; j < 39; j++) 
                {
                    stages[i][j] = sta[i][j];
                }
            }
            return stages;
            break;
        }
        case 3:
        {
            char sta[16][40] = 
            {
                "* * * * * * * * * * * * * * * * * * * *",
                "* s                                   *",
                "*  **                  ###########    *", 
                "*         ############# $        #  $ *",   
                "*     #   *********************  #    *",    
                "*######             *     $      #    *",    
                "*    $              *   #        #    *",
                "* #####             *   #             *",
                "*      #############*## #             *",
                "*      #####     ###* $ #             *",
                "*                  $*   #             *",
                "*         *********************       *",
                "***###                                *",
                "***###            #########           *",
                "******                               $*",
                "***************************************",
            };
            p.x = 1;
            p.y = 1;
            for (int i = 0; i < 16; i++) 
            {
                for (int j = 0; j < 39; j++) 
                {
                    stages[i][j] = sta[i][j];
                }
            }
            return stages;
            break; 
        }

        default: 
        {
            printf("Congrats!You've reach the END!");
            exit(0);
        }
    }
}

void moveplayer(char **stages, char move) 
{
    int newx = p.x, newy = p.y;
    if (move == 'w' || move == 'W' || move == '8') 
    {
        (newy)--;
    } else if (move == 'a' || move == 'A' || move == '4') 
    {
        (newx)--;
    } else if (move == 's' || move == 'S' || move == '2') 
    {
        (newy)++;
    } else if (move == 'd' || move == 'D' || move == '6') 
    {
        (newx)++;
    } else 
    {
        printf("invalid input:\n");
        return;
    }

    if ((stages[newy][newx] == 'E') && (newy == 2) && (newx == 38)) 
    {
        stages[newy][newx] = 'P';
        stages[p.y][p.x] = ' ';
        p.x = newx;
        p.y = newy;
        return;
    }

    if ((stages[newy][newx] == ' ') && (newy < 16) && (newx < 39) && (newy > 0) && (newx > 0)) 
    {
        stages[newy][newx] = 'P';
        stages[p.y][p.x] = ' ';
        p.x = newx;
        p.y = newy;
    } else if ((stages[newy][newx] == '#'||stages[newy][newx]=='Z'||stages[newy][newx]=='X') && (newy < 16) && (newx < 39) && (newy > 0) && (newx > 0))
    {
        stages[newy][newx] = 'P';
        stages[p.y][p.x] = ' ';
        p.x = newx;
        p.y = newy;
        top--;
    } else if ((stages[newy][newx] == '$') && (newy < 16) && (newx < 39) && (newy > 0) && (newx > 0)) 
    {
        stages[newy][newx] = 'P';
        stages[p.y][p.x] = ' ';
        p.x = newx;
        p.y = newy;
        p.money[++topm] = '$';
    }
    return;
}

void moveenemies(char **stage) 
{
    for (int i = 0; i < 10; i++) 
    {
        if (enemies[i].health <= 0) 
        continue;

        char move = enemies[i].moves[enemies[i].current_move];
        enemies[i].current_move = (enemies[i].current_move + 1) % 4;

        int newx = enemies[i].x;
        int newy = enemies[i].y;

        if (move == 'w') 
        newy--;
        else if (move == 'a') 
        newx--;
        else if (move == 's') 
        newy++;
        else if (move == 'd') 
        newx++;


        if (stage[newy][newx] == ' ' || stage[newy][newx] == 'P') 
        {
            stage[enemies[i].y][enemies[i].x] = ' ';
            stage[newy][newx] = enemies[i].symbol;
            enemies[i].x = newx;
            enemies[i].y = newy;
        }
    }
}

void stage_clear(char **stage) 
{
    for (int i = 0; i < 16; i++) 
    {
        free(stage[i]);
    }
    free(stage);
}
