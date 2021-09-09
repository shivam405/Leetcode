class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;

        node(int _key,int _value)
        {
            key=_key;
            value=_value;
        }
    };

    //craete two dummy node
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);

    int cap;
    unordered_map<int,node*> m;

    LRUCache(int capacity){
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    
    void addnode(node* newnode) {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    int get(int key){
        //present in tha map
        if(m.find(key)!=m.end())
        {
            node* resnode=m[key];
            int res=resnode->value;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key,int value){
        //present in the map
       if(m.find(key)!=m.end()) {
           node* existing_node=m[key];
           m.erase(key);
           deletenode(existing_node);
       }
       //mapsize is equal to capacity
       if(m.size()==cap)
       {
           m.erase(tail->prev->key);
           deletenode(tail->prev);
       }
       addnode(new node(key,value));
       m[key]=head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */