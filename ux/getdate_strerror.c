
const char *getdate_strerror(int e)
{
	const char *s[] = {
		"Invalid getdate_err value",
		"DATEMSK environment variable null or undefined",
		"Template file cannot be opened for reading",
		"Failed to get file status information",
		"Template file not a regular file",
		"I/O error encountered while reading template file",
		"Memory allocation failed",
		"No line in template that matches input",
		"Invalid input specification"
	};
	if (e < 1 || e > 8)
		return s[0];
	return s[e];
}
