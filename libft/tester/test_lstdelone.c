#include "../libft.h"

void    test_lstdelone()
{
    t_list  *l;

    printf("\033[0;31mft_lstdelone:   \033[0m ");
    l = ft_lstnew(malloc(1));
    ft_lstdelone(l, free);
    if (l->content != NULL)
       printf(" \033[0;31mKO \033[0m");
    else
        printf("\033[0;32mOK \033[0m");
    printf("\n");
}

int main()
{
    test_lstdelone();
    return 0;
}