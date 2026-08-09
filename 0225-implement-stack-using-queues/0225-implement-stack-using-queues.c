


typedef struct {
    int data[100];
    int front;
    int rear;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack *obj= (MyStack *)malloc(sizeof(MyStack));

    obj->front=0;
    obj->rear=0;
    obj->size=0;

    return obj; 
}

void myStackPush(MyStack* obj, int x) {
    obj->data[obj->rear]=x;
    obj->rear= (obj->rear+1)%100;
    obj->size++;

    for(int i=0;i<obj->size-1;i++)
    {
        int temp = obj->data[obj->front];

        obj->front= (obj->front+1)%100;

        obj->data[obj->rear]=temp;
        obj->rear=(obj->rear +1)%100;
    }
}

int myStackPop(MyStack* obj) {
    int x= obj->data[obj->front];

    obj->front=(obj->front + 1)%100;
    obj->size--;
    return x;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size==0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/