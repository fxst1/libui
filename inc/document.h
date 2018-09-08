#ifndef DOCUMENT_H
# define DOCUMENT_H
# include <fcntl.h>
# include "hashmap.h"
# define DOCUMENT_XML "XML"
# define DOCUMENT_CSS "CSS"
# define DOCUMENT_JSON "JSON"
# define DOCUMENT_RAW "RAW"

/*
**	XML
*/

typedef struct			s_xml_node
{
	t_hashmap			*attributes;
	struct s_xml_node	*last;
	struct s_xml_node	*next;
	struct s_xml_node	*parent;
	struct s_xml_node	*child;
}						t_xml_node;

typedef struct			s_xml_document
{
	int					version;
	int					encoding;
	t_xml_node			*root;
}						t_xml_document;

/*
**	CSS
*/

typedef struct			s_css_rule
{
	char				*rulename;
	t_hashmap			*attributes;
}						t_css_rule;

typedef struct			s_css_document
{
	int					version;
	t_list				*rules;
}						t_css_document;

/*
**	JSON
*/

typedef union			s_json
{
	t_hashmap			*object;
	t_list				*array;
	char				*string;
	double				number;
}						t_json;

typedef struct			s_json_document
{
	t_json				*data;
}						t_json_document;

/*
**	RAW
*/

typedef struct			s_raw_document
{
	size_t				size;
	unsigned char		*buffer;
}						t_raw_document;

/*
**	DOCS
*/

typedef union			u_document_data
{
	t_xml_document		*xml;
	t_css_document		*css;
	t_json_document		*json;
	t_raw_document		*raw;
}						t_document_data;

typedef struct			s_document
{
	int					status;
	int					type;
	char				*filename;
	char				*buffer;
	int					(*read)(struct s_document*, void*);
	t_document_data		data;
}						t_document;

t_document				*document_open(const char *filename, const char *typefile);

#endif
