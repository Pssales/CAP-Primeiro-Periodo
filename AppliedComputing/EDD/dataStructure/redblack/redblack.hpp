#ifndef __REDBLACK__
#define __REDBLACK__

#define RED 1
#define BLACK 0

template<class T>
class RedBlack{

    public:
        struct Node
        {
            Node * left;
            Node * right;
            Node * parent;
            T value;
            bool color;
        };

        RedBlack();
        ~RedBlack();

        Node getRoot();
        int level(Node * n);

        void insert(const T& value);
        void remove(Node * position);

        void print(Node);
        void preOrder(Node * n);
        void inOrder(Node * n);
        void posOrder(Node * n);

        bool color(Node * n);
        void changeColor(Node * n);
    
    private:
        RedBlack(RedBlack&);
        RedBlack& operator =(Tree&);
    
    private:
        Node * root;

};


#endif  
