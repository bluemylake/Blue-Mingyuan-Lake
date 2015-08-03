#!perl
use 5.010;

my @defalt=qw(id type 0 0 -1 -1 0 0 0 0);
my @name=qw(id type x y cat imgNo nPre nDia nArg repeat);
my @typeName=qw(Talk Super Dialog Shadow Reload Bloody Watery Duel 
	LNight LDay IsWin);

my $first=1;
$out=STDOUT;
$^I=".bak";
print "============= begin ==================\n";

while(<>){
	if($first==1){ print; $first=0; next; }

	chomp;
	my ($x, $y, $des, $id, $cat, $type, $imgNo, $next, 
		$nPre, $nDia, $nArg, $repeat, @list)=split /,/;

	#print $out $_, "\n"; 
	#print "$x, $y, $id, $cat, $type, $imgNo, $next, ",
		#"$nPre, $nDia, $nArg, $repeat, ", @list, "\n";
	#print "x, y, id, cat, type, imgNo, next, nPre, nDia, nArg, repeat, \n";

	($id,$type,$x,$y,$cat,$imgNo,$nPre,$nDia,$nArg,$repeat)=fillEmpty(
		$id,$type,$x,$y,$cat,$imgNo,$nPre,$nDia,$nArg,$repeat);

	given($type) {
		when(/^[145689]$/)	{
			if($x!=0 || $y!=0){
				print $out "Alert: $id event xy not zero, may not be $type\n";
			}
			putDefault($id,$type,$x,$y,$cat,$imgNo,$nPre,$nDia,$nArg,$repeat);
		}
		when(0) {
			if($x<=10 || $y<=10){
				print $out "Manul: $id event of type $typeName[$type]($type) ",
					"xy ($x, $y) not set\n";
			}
			if($cat<0 || $cat>2){ $cat=1; }
			if($imgNo<1 || $imgNo>22){
				print $out "Alert: $id NPC IMG $imgNo set to default\n"; 
				$imgNo=1; 
			}
			if($nDia<1){
				$nDia=0; print $out "Alert: $id NPC has nothing to say\n";
			}
		}
		when(2) {
			if($nDia<1){
				print $out "Alert: $id obj on map has nothing to say\n";
				$nDia=0; 
			}
		}
		when(3) {
			if($imgNo<1 || $imgNo>22){
				#print "Alert: $id BF IMG $imgNo set to default\n"; $imgNo=1; 
			}
			if($nArg<0 || $nArg>1){
				print $out "Error: $id BF event nArg=$nArg. ",
					"Should be [0,1]\n";
			}
		}
		when(7) {
			if($x!=0 || $y!=0){
				print $out "Alert: $id event xy not zero, may not be $type\n";
			}
			if($nArg<1){
				print $out "Alert: $id Duel event should have an arg\n";
			}
		}
		when(10) {
			if($nArg<1 || $nArg>2){
				print $out "Error: $id IsWin event nArg=$nArg. ",
					"Should be [1,2]\n";
			}
		}
		default {
			print $out "Error: $id event type $typeName[$type]($type) ",
				"unrecognize\n";
		}
	}

	my $arg0=0, $dia0=$nArg, $pre0=$nArg+$nDia;
	my $len=$nPre+$nDia+$nArg;
	my $actual=countNonempty(@list);
	if($len!=$actual){
		print $out "Error: $id event list length error. ",
			"Sum=$len vs List=$actual\n";
	}

	$"=",";
	print "$x,$y,$des,$id,$cat,$type,$imgNo,$next,",
		"$nPre,$nDia,$nArg,$repeat,@list\n";
}

# count non-empty elems
sub countNonempty{
   my $count=0;
   foreach my $val (@_){
	   if(length $val!=0){
		   $count++;
	   }
   }
   $count;
}

# after calling this func, no att is empty 
sub fillEmpty{
	for($i=2;$i<@_;$i++){
		if(length $_[$i]==0){
			$_[$i]=$defalt[$i];
		}
	}
	@_;
}

# put default to [145678910]
sub putDefault{
	for($i=2;$i<@_;$i++){
		if($_[$i]!=$defalt[$i]){
			print $out "Alert: $_[0] event of type $typeName[$_[1]]($_[1]) ",
				"$name[$i] set from $_[$i] to default\n";
			$_[$i]=$defalt[$i];
		}
	}
	@_;
}

