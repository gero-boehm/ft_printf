#include "include/ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	print_tag(t_tag *tag)
{
	char *prefixes[] = {"", "-", "+", " ", "0x", "0X"};

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
	printf("  result:\n");
	printf("    str:           '%s'\n", tag->result.str);
	printf("    pefix:         '%s'\n", prefixes[tag->result.prefix]);
	printf("    size_virtual:  %zu\n", tag->result.size_virtual);
	printf("    size_actual:   %zu\n", tag->result.size_actual);
	printf("}\n");
}

int	main(void)
{
	t_buffer buffer;
	t_tag tag;

	(void) tag;
	(void) buffer;

	const char *format = "%+d--";
	// if (init_buffer(format, &buffer))
	// 	return (1);
	// init_tag(&tag);
	// if (parse_tag(&buffer, &tag))
	// 	return (2);
	// tag.result.str = strdup("1");
	// tag.result.prefix = PREFIX_0X_LOWER;
	// tag.result.size_virtual = 1;
	// tag.result.size_actual = 0;
	// print_tag(&tag);
	// if (apply_precision(&tag))
	// 	return (3);
	// if (apply_prefix(&tag))
	// 	return (4);
	// printf("%s\n", tag.result.str);

	ft_printf(format, 5);

	// printf("%.5%");

	// printf("% u\n", 5);

	// for(int i = 0; i < 32; i++)
	// {
	// 	// char *str = calloc(2, 1);
	// 	// *str = (char) i;
	// 	int n = printf("%3d ('%c' ", i, (char) i);
	// 	printf("%d)\n", n);
	// 	// free(str);
	// }

	// printf("%d\n", strlen("\x27"));
	// printf("'%05c'\n", 31);

	// char *str = malloc(20);
	// itoa_base2(1589, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(-1589, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(0, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(-0, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(-1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);

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