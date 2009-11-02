#! /usr/bin/perl

$HERE=`/bin/sh -c pwd`;
$BASENAME=`basename $HERE`;
chomp($BASENAME);
$INSERT="#include <GsTLAppli/$BASENAME/common.h>";

foreach $file (`find . -name "*.h" | grep -v "/common"`) {
  print "working on file: $file";
  $LINE=`grep -m 1 "#include" $file`;
  chomp($LINE);

  $BEFORE=1;

  if( $LINE =~ /include/ ) {
  }
  else {
    $LINE="#define __GSTLAPPLI_";
    $BEFORE=0;
  }

  print "LINE= $LINE\n";
  #$LINE =~ s:/:\\/:g;
  #print "LINE= $LINE\n";

  open( IN, $file );
  open OUTFILE, ">.tmp.txt";

  while(<IN>) {
    chomp($_);
    if(/$LINE/) {
      if($BEFORE==1) {
        print OUTFILE "$INSERT\n";
        print OUTFILE "$_ \n";
      }
      else {
        print OUTFILE "$_ \n\n";
        print OUTFILE "$INSERT\n";

      }
    }
    else {
      print OUTFILE "$_ \n";
    }
  }

`mv .tmp.txt $file`
}
