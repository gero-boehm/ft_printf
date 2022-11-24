#include "include/ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	print_tag(t_tag *tag)
{
	char *prefixes[] = {"", "-", "+", " ", "0x"};

	printf("t_tag {\n");
	printf("  properties:\n");
	printf("    left_justify:  %d\n", tag->properties.left_justify);
	printf("    plus:          %d\n", tag->properties.plus);
	printf("    space:         %d\n", tag->properties.space);
	printf("    prefix:        %d\n", tag->properties.prefix);
	printf("    zeroes:        %d\n", tag->properties.zeroes);
	printf("    padding:       %d\n", tag->properties.padding);
	printf("    precision:     %d\n", tag->properties.precision);
	printf("    specifier:     %c\n", tag->properties.specifier);
	printf("  range:\n");
	printf("    start:         %d\n", tag->range.start);
	printf("    length:        %zu\n", tag->range.length);
	printf("  parts:\n");
	printf("    str:           '%s'\n", tag->parts.str);
	printf("    pefix:         '%s'\n", prefixes[tag->parts.prefix]);
	printf("    size_virtual:  %zu\n", tag->parts.size_virtual);
	printf("    size_actual:   %zu\n", tag->parts.size_actual);
	printf("  construct:\n");
	printf("    str:           '%s'\n", tag->construct.str);
	printf("    size_virtual:  %zu\n", tag->construct.size_virtual);
	printf("    size_actual:   %zu\n", tag->construct.size_actual);
	printf("}\n");
}

int	main(void)
{
	t_buffer buffer;
	t_tag tag;

	(void) tag;
	(void) buffer;

	const char *format = "%.5d";
	if (init_buffer(&buffer, format))
		return (1);
	init_tag(&tag);
	if (parse_tag(&tag, &buffer))
		return (2);
	tag.parts.str = strdup("1");
	print_tag(&tag);
	if (apply_precision(&tag))
		return (3);
	printf("%s\n", tag.construct.str);

	// if (advance_cursor(&buffer))
	// 	return (2);
	// printf("%d\n", buffer.size_actual);

	// char *s1 = strdup("test");
	// padstr2(20, 0, 0, &s1);
	// printf("'%s'\n", s1);
	// char *s2 = strdup("test");
	// padstr2(20, 1, 0, &s2);
	// printf("'%s'\n", s2);
	// char *s3 = strdup("test");
	// padstr2(20, 0, 1, &s3);
	// printf("'%s'\n", s3);
	// char *s4 = strdup("test");
	// padstr2(20, 1, 1, &s4);
	// printf("'%s'\n", s4);
	// char *s5 = strdup("test");
	// padstr2(2, 0, 0, &s5);
	// printf("'%s'\n", s5);


	// // printf("%10.5d\n", -10);
	// // printf(" | %d\n", printf("'%03c'", 0));
	// // printf(" | %d\n", printf("'%s'", ""));

	// printf("%.3c\n", 'a');
	// printf("%.3s\n", "abcdef");
	// printf("%.3p\n", "s");
	// printf("%.3d\n", 1);
	// printf("%.3i\n", 1);
	// printf("%.3u\n", 1);
	// printf("%.3x\n", 15);
	// printf("%10.30X\n", 15);
	// printf("%.3%\n");


	return (0);
}