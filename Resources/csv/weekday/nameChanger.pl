#!perl

while(<STDIN>)
{
	print $_;
	chomp;
	my $old=$_;
	if(m/event\d\d\d/)
	{
		s/event(\d)\d(\d)/map\1_day\2/;
		print "mv $old $_";
		system "mv $old $_";
	}
}
