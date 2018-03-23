#include "lem-in.h"

t_read	*new_read_node(char *str)
{
	t_read	*new;

	new = (t_read *)malloc(sizeof(t_read));
	new->line = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_read	*initial_read(void) //func to read the stdio for the validation and further processing;
{
	char *line;
	t_read *head;
	t_read *current;

	line = NULL;
	head = NULL;
	current = NULL;
	while (get_next_line(0, &line))
	{
		if (!current)
		{
			current = new_read_node(line);
			head = current;
			// ft_printf("%s\n", current->line);
		}
		else
		{
			while (current->next)
				current = current->next;
			current->next = new_read_node(line);
			// ft_printf("%s\n", current->line);
		}
	}
	return (head);
}

void	print_list(t_data *test)
{
	t_read *head;

	head = test->initial_information;
	while(head)
	{
		ft_printf("%s\n", head->line);
		head = head->next;
	}
}

int main(void)
{
	t_data test;
	test.initial_information = NULL;

	test.initial_information = initial_read();
	print_list(&test);
	return 0;
}