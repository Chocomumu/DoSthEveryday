typedef struct{
    int val;
    struct Node *next;
    struct Node *pre;
}Node;
char * reverseParentheses(char * s){
    if(s==NULL)
        return s;
    int s_len = strlen(s);
    char *res = (char *)malloc(s_len*sizeof(char)+1);
    char *tmp = res;
    Node n = {0,NULL,NULL};
    Node *tail = &n;
    int resIndex = 0;
    while(*s!=0){
        while(*s!=0&&*s!=')'){
            if(*s=='('){
                Node *Ntmp = (Node*)malloc(sizeof(Node));
                Ntmp->val = resIndex;
                Ntmp->next = NULL;
                Ntmp->pre = tail;
                tail->next = Ntmp;
                tail = tail->next;
            }
            res[resIndex++] = *s++;
        }
        if(*s!=0&&*s==')'){
            int i = tail->val;
            tail = tail->pre;
            free(tail->next);
            tail->next = NULL;
            res[i] = res[resIndex-1];
            resIndex--;
            swap(res,i+1,resIndex-1);
            s++;
        }
    }
    res[resIndex]=0;
    return res;
}
void swap(char* s,int begin,int end){
    for(int i=0;i<=(end-begin)/2;i++){
        char temp = s[begin+i];
        s[begin+i] = s[end-i];
        s[end-i]=temp;
    }
}
