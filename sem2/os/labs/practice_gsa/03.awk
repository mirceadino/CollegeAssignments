BEGIN {
	FS=":"
	OFS=":"
}

{
	if($3 % 7 == 0)
		print $1, $5
}

END {
}
