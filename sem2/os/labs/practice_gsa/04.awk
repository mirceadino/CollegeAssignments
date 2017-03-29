BEGIN {
}

{
	if($1 == "root")
		print $6
}

END {
}
