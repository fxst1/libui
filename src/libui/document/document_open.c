#include "document.h"

static t_document	*document_init(const char *filename, const char *typefile, t_list *reader, size_t total_size)
{
	t_document		*doc;
	t_list			*tmp;
	char			*buffer;
	size_t			size;

	size = 0;
	buffer = (char*)ft_strnew(total_size);
	while (reader)
	{
		tmp = reader->next;
		ft_strcpy(buffer + size, (char*)reader->content);
		size += reader->content_size;
		free(reader->content);
		free(reader);
		reader = tmp;
	}
	doc = (t_document*)malloc(sizeof(t_document));
	if (!doc)
		return (NULL);
	doc->filename = (char*)filename;
	if (!ft_strcmp(typefile, DOCUMENT_XML))
		document_xml(doc, buffer);
	free(buffer);
	return (doc);
}

t_document			*document_open(const char *filename, const char *typefile)
{
	t_list		*reader;
	char		buffer[1024];
	int			fd;
	ssize_t		size;
	size_t		total_size;

	reader = NULL;
	fd = open(filename, O_RDONLY);
	size = 0;
	total_size = 0;
	if (fd <= 0)
		return (NULL);
	while ((size = read(fd, buffer, 1024)) > 0)
	{
		ft_lstadd(&reader, ft_lstnew(buffer, size));
		total_size += size;
	}
	if (size < 0)
		return (NULL);
	else
		close(fd);
	return (document_init(filename, typefile, reader, total_size));
}
