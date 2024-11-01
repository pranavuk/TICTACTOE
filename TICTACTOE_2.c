#include<stdio.h>
int array[3][3];
int slot;

int check(int m, int n) {
    int count = 0;

    // Check rows
    for(int i = 0; i < 3; i++) {
        count = 0;
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == n) {
                count++;
            }
            else {
                    slot=i+j*3;
            }
        }
        if (count==m) {
            if(m==2 && !array[slot%3][slot/3]){
                array[slot%3][slot/3]=3;
                return 1;
            }
            else if(m!=2){
                return 1;
            }
        }
    }

    // Check columns
    for(int i = 0; i < 3; i++){
        count = 0;
        for (int j = 0; j < 3; j++) {
            if (array[j][i] == n) {
                count++;
            }
            else{
                slot=j+i*3;
            }
        }
        if (count == m) {
            if(m==2 && !array[slot%3][slot/3]){
                array[slot%3][slot/3]=3;
                return 1;
            }
            else if(m!=2){
                return 1;
            }
        }

    }

    // Check primary diagonal
    count = 0;
    for(int i=0;i<3;i++){
            if (array[i][i] == n) {
                count++;
            }
            else{
                    slot=i+i*3;// Store the position of the empty slot
            }
    }
        if (count == m) {
            if(m==2 && !array[slot%3][slot/3]){
                array[slot%3][slot/3]=3;
                return 1;
            }
            else if(m!=2){
                return 1;
            }
        }
    // Check secondary diagonal
    count = 0;
    for(int i=0; i < 3; i++){
            if (array[i][2-i] == n) {
                count++;
            }
            else{
                    slot=i+(2-i)*3;// Store the position of the empty slot
            }
    }
        if (count == m) {
            if(m==2 && !array[slot%3][slot/3]){
                array[slot%3][slot/3]=3;
                return 1;
            }
            else if(m!=2){
                return 1;
            }
        }

    return 0; // No win found
}

int winuser(){
if(check(3,2)){
    return 1;
}
return 0;
}

int winbot(){
if(check(3,1)){
    return 1;
}
return 0;
}
void input(){
    int n=0;
    printf("choose a tile to fill: \n");
    scanf("%d",&n);
    if(array[(n-1)/3][(n-1)%3]){
        printf("slot is already occupied try again! \n");
        input();
    }
    else{
        array[(n-1)/3][(n-1)%3]=2;
    }
}

void print(){
    int i,j;
    printf("\n\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(!array[i][j]){
                printf(" ");
            }
            if(array[i][j]==1){
                printf("X");
            }
            if(array[i][j]==2){
                printf("O");
            }
            if(j!=2){
                printf("|");
            }
        }
        printf("\n");
        if(i!=2){
            printf("------");
            printf("\n");
        }
    }
    printf("\n\n");
}

int block(){
    int i;
if(check(2,2)){
        array[slot%3][slot/3]=1;
        return 1;
    }
return 0;
}

int win(){
    if(check(2,1)){
        array[slot/3][slot%3]=1;
        return 1;
    }
    return 0;
}

int play(){
    if(block()){
        return 1;
    }
    else if(win()){
        return 1;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!array[i][j]){
                array[i][j]=1;
                return 1;
            }
        }
    }
    return 1;   
}

int tie(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!array[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int game(){
    while(1){
        input();
        print();
        if(winuser()){
            print();
            printf("user wins. \n");
            return 0;
        }
        play();
        print();
        if(winbot()){
            print();
            printf("bot wins. \n");
            return 0;
        }
        if(tie()){
            printf("its a tie. \n");
            return 0;
    }
    }
}

void initialise(){
    for(int i=0;i<5;i++){
    }
    printf("slots are numbered as:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            array[i][j]=0;
            printf("%d",j+1+i*3);
            if(j!=2)
                printf("|");
        }

        if(i!=2){
            printf("\n------\n");
        }
    }
    printf("\n");
}

int main(){
    int command;
    while(1){
        printf("enter 1 to start the game \nenter 0 to exit.\n");
        scanf("%d",&command);
        if(!command){
            printf("thanks for playing.");
            return 0;
        }
        initialise();
        game();
    
    }

}