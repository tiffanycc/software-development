#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

/* define a struct of squad members*/
typedef struct member
{
    char *name;
    int move;
    int fight;
    int shoot;
    int armour;
    int morale;
    int health;
    int cost;
    char *note;
}mem;


void main()
{
    int count_soldier,count_captain_item,count_hierophant_item;
    int specialism_captain_size,specialism_hierophant_size;
    int specialism_captain_index,specialism_hierophant_index;
    int squad_index[8],items_captain_index[6],items_hierophant_index[4];
    char squad_name[20];
    char public_state[2];
    char *specialism_captain[]={"specialism_1","specialism_2","specialism_3","specialism_4"};
    char *specialism_hierophant[]={"specialism_1","specialism_2","specialism_3","specialism_4"};
    char *items[]={"item1","item2","item3","item4","item5","item6","item7","item8","item9","item10",\
    "weapon1","weapon2","weapon3","weapon4"};
    mem soldier[10]={
        {"name1",1,1,1,1,1,1,1,"note1"},
        {"name2",2,2,2,2,2,2,2,"note2"},
        {"name3",3,3,3,3,3,3,3,"note3"},
        {"name4",4,4,4,4,4,4,4,"note4"},
        {"name5",5,5,5,5,5,5,5,"note5"},
        {"name6",6,6,6,6,6,6,6,"note6"},
        {"name7",7,7,7,7,7,7,7,"note7"},
        {"name8",8,8,8,8,8,8,8,"note8"},
        {"name9",9,9,9,9,9,9,9,"note9"},
        {"name10",10,10,10,10,10,10,10,"note10"}
    };

    int choose_member(int *squad_index,mem *soldier);
    int choose_items_captain(int *items_captain_index,char **items);
    int choose_items_hierophant(int *items_captain_index,int *items_hierophant_index,char **items,int count_captain);

    /*get specialism tree size*/
    specialism_captain_size=sizeof(specialism_captain)/sizeof(specialism_captain[0]);
    specialism_hierophant_size=sizeof(specialism_hierophant)/sizeof(specialism_hierophant[0]);

    /*get squad name*/
    printf("****************STEP ONE:NAME*********************\n");
    printf("Please enter squad name:\n");
    scanf("%s",&squad_name);
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("Do you want to public your squad?y/n\n");
    scanf("%s",&public_state);
    //public_state=getchar();

    /*get captain specialism*/
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("\n\n****************STEP TWO:SPECIALISM*********************\n");
    printf("\nPlease choose one specialism for captain by enter the number:\nCaptain specialism:\n");
    for(int i=0;i<specialism_captain_size;i++)
        printf("\t%d:%s\n",i+1,specialism_captain[i]);
    scanf("%d",&specialism_captain_index);

    /*get hierophant specialism*/
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("\nPlease choose one specialism for hierophant:\nHierophant specialism:\n");
    for(int i=0;i<specialism_hierophant_size;i++)
        printf("\t%d:%s\n",i+1,specialism_hierophant[i]);
    scanf("%d",&specialism_hierophant_index);



    /*choose the soldier for the members*/
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("\n\n****************STEP THREE:MEMBERS*********************\n");
    count_soldier=choose_member(squad_index,soldier);



    /*get captain items*/
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("\n\n****************STEP FOUR:ITEMS*********************\n");
    count_captain_item=choose_items_captain(items_captain_index,items);


    /*get hierophant items*/
    printf("\nOKAY!\n");
    Sleep(1000);
    count_hierophant_item=choose_items_hierophant(items_captain_index,items_hierophant_index,items,count_captain_item);



    /*print out the squad information*/
    printf("\nOKAY!\n");
    Sleep(1000);
    printf("\n\n****************RESULTS*********************\n");
    printf("THANK YOU FOR YOUR PATIENCE,HERE IS YOUR SQUAD:\n\nNAME:%s\n\n",&squad_name);//name
    printf("PUBLIC_STATE:%s\n\n",public_state);
    printf("CAPTAIN SPECIALISM:%s\n",specialism_captain[specialism_captain_index-1]);//specialism
    printf("\nHIEROPHANT SPECIALISM:%s\n",specialism_hierophant[specialism_hierophant_index-1]);
    printf("\nSQUAD MEMBER:\n");//squad members
    for(int j=0;j<count_soldier;j++)
    {
        int i;
        i=squad_index[j]-1;
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\n",i+1,soldier[i].name,soldier[i].move,\
               soldier[i].fight,soldier[i].shoot,soldier[i].armour,soldier[i].morale,\
               soldier[i].health,soldier[i].cost,soldier[i].note);
    }

    printf("\nCAPTAIN ITEMS:\n");//items
    for(int j=0;j<count_captain_item;j++)
    {
        int i;
        i=items_captain_index[j]-1;
        printf("%d:%s\t",i+1,items[i]);
    }

    printf("\n\nHIEROPHANT ITEMS:\n");//items
    for(int j=0;j<count_hierophant_item;j++)
    {
        int i;
        i=items_hierophant_index[j]-1;
        printf("%d:%s\t",i+1,items[i]);
    }
    printf("\n\nEND!\n\n");
}

/*this function is for the squad member choosing*/
int choose_member(int *squad_index,mem *soldier)
{
    *squad_index=0;
    int count=0,flag=0;

    printf("\nPlease choose squad members!\n");
    printf("\nNumber\tName\tMove\tFight\tShoot\tArmour\tMorale\tHealth\tCost\tNote\n");
    for(int i=0;i<10;i++)
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\n",i+1,soldier[i].name,soldier[i].move,\
               soldier[i].fight,soldier[i].shoot,soldier[i].armour,soldier[i].morale,\
               soldier[i].health,soldier[i].cost,soldier[i].note);
    printf("\nChoose up to 8 soldiers!\nPlease enter the number of the soldier in a single line,separate by comma and end by #:\n");
    /*read in the chosen members number*/
    do
    {
        scanf("%d",&squad_index[count]);
        count+=1;
    }while((getchar())!='#');

    /*check validity of the chosen number to fit the requirement*/
    for(int i=0;i<count;i++)
    {
        if(squad_index[i]<1||squad_index[i]>10)
        {
            printf("\nERROR:Invalid soldier number!Please enter the number in the table above in a single line.\n");
            Sleep(1000);
            flag=1;
        }
        else
        {
            for(int j=0;j<i;j++)
                if(squad_index[i]==squad_index[j])
                {
                    printf("\nERROR:Please do not choose the same soldier twice.\n");
                    Sleep(1000);
                    flag=1;
                    break;
                }
        }
    }
    if(count>8)
    {
        flag=1;
        printf("\nERROR:Please do not choose more than 8 soldiers.\n");
    }

    /*decide if the input are right, then return the input number count*/
    if(flag)
        choose_member(squad_index,soldier);
    else
        return count;
}


/*this function is for choosing captain items*/
int choose_items_captain(int *items_captain_index,char **items)
{
    *items_captain_index=0;
    int a=0,flag=0,count=0;

    printf("\nplease choose items for captain:\n\n");
    for(int i=0;i<14;i++)
        printf("%d: %s\n",i+1,items[i]);
    printf("\nPlease enter up to 6 items for captain in a single line,\nup to 2 can be weapons,separate by comma and end by #:\n");
    /*read in the chosen items number*/
    do
    {
        scanf("%d",&items_captain_index[count]);
        count+=1;
    }while((getchar())!='#');

    /*check validity of the chosen number to fit the requirement*/
    for(int i=0;i<count;i++)
    {
        if(items_captain_index[i]>10)a++;
        if(items_captain_index[i]<1||items_captain_index[i]>14)
        {
            printf("\nERROR:Invalid item number!Please enter the number in the table above in a single line.\n");
            Sleep(1000);
            flag=1;
        }
        else
        {
            for(int j=0;j<i;j++)
                if(items_captain_index[i]==items_captain_index[j])
                {
                    printf("\nERROR:Please do not choose the same item twice.\n");
                    Sleep(1000);
                    flag=1;
                    break;
                }
        }

    }
    if(count>6)
    {
        flag=1;
        printf("\nERROR:Please do not choose more than 6 items.\n");
        Sleep(1000);
    }

    /*limited weapons number to 2*/
    if(a>2)
    {
        flag=1;
        printf("\nERROR:Please do not choose more than 2 weapons.\n");
        Sleep(1000);
    }

    if(flag)
        choose_items_captain(items_captain_index,items);
    else
        return count;
}


/*this function is for choosing hierophant items*/
int choose_items_hierophant(int *items_captain_index,int *items_hierophant_index,char **items,int count_captain)
{
    *items_hierophant_index=0;
    int a=0,flag=0,flag1=0,count=0;
    printf("\nplease choose items for hierophant:\n\n");
    for(int i=0;i<14;i++)
    {
        flag1=0;
        for(int j=0;j<count_captain;j++)
            if(i+1==items_captain_index[j])flag1=1;
        if(!flag1)printf("%d: %s\n",i+1,items[i]);
    }
    printf("\nPlease enter up to 4 items for hierophant in a single line,\nup to 1 can be weapons,separate by comma and end by #:\n");

    /*read in the chosen items number*/
    do
    {
        scanf("%d",&items_hierophant_index[count]);
        count+=1;
    }while((getchar())!='#');

    /*check validity of the chosen number to fit the requirement*/
    for(int i=0;i<count;i++)
    {
        if(items_hierophant_index[i]>10)a++;
        for(int j=0;j<count_captain;j++)
            if(items_hierophant_index[i]==items_captain_index[j])
            {
                flag=1;
                printf("\nERROR:Invalid item number!ITEM%d has been chosen by captain,please choose other items.\n",items_hierophant_index[i]);
                Sleep(1000);
            }
        if(items_hierophant_index[i]<1||items_hierophant_index[i]>14)
        {
            printf("\nERROR:Invalid item number!Please enter the number in the table above in a single line.\n");
            Sleep(1000);
            flag=1;
        }
        else
        {
            for(int j=0;j<i;j++)
                if(items_hierophant_index[i]==items_hierophant_index[j])
                {
                    printf("\nERROR:Please do not choose the same item twice.\n");
                    Sleep(1000);
                    flag=1;
                    break;
                }
        }
    }
    if(count>4)
    {
        flag=1;
        printf("\nERROR:Please do not choose more than 4 items.\n");
        Sleep(1000);
    }

    /*limited weapons number to 1*/
    if(a>1)
    {
        flag=1;
        printf("\nERROR:Please do not choose more than 1 weapons.\n");
        Sleep(1000);
    }
    if(flag)
        choose_items_hierophant(items_captain_index,items_hierophant_index,items,count_captain);
    else
        return count;
}
