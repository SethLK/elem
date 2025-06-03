typedef struct
{
    enum
    {
        AST_NUMBER,
        AST_ADD,
        AST_MUL,
    } tag;

    union
    {
        struct AST_NUMBER
        {
            int number;
        } AST_NUMBER;

        struct AST_ADD
        {
            AST *left;
            AST *right;
        } AST_ADD;

        struct AST_MUL
        {
            AST *left;
            AST *right;
        } AST_MUL;
    } data;

} AST;


AST *ast_new(AST ast);