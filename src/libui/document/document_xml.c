#include "libui.h"

static char		*get_tag(char *start)
{
	while ()
}

static void		get_node(t_xml_document *doc, t_xml_node **root, char **buffer)
{
	char		*tag;
	char		*tagend;

	if (!ft_strncmp(*buffer, "<?xml", 5))
	{
		tag = (*buffer) + 5;
		tagend = ft_strstr(tag, "?>");
		if (!tagend)
			write(STDERR_FILENO, "Error\n", 6);
		else
			while (tag < tagend)
			{

				tag++;
			}
	}
}

t_document		*document_xml(t_document *doc, char *buffer)
{
	t_xml_document	*xml;
	t_xml_node		*node;

	xml = (t_xml_document*)malloc(sizeof(t_xml_document));
	doc->data = xml;
	node = NULL;
	while (*buffer)
	{
		if (*buffer == '<')
			get_node(node, &node);
		buffer++;
	}
}
