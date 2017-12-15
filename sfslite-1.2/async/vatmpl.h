#if 0 /* -*-perl-*- */

# /*
# $Id: vatmpl.h 2174 2006-08-30 18:05:30Z max $
# 
# This header file was automatically generated by itself.
# (Yup, it's a C++ header file and a perl script.)
#

# Copyright (C) 1998 David Mazieres (dm@uun.org)
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2, or (at
# your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA
#
# Note: For the purposes of the GNU General Public License, source
# includes the source to the perl script, not just the resulting
# header file, callback.h.  However, since the perl script is
# conveniently embedded in the header file, you needn't do anything
# special to distribute source as long as you don't take the perl out
# of the header.

eval 'exec perl -w -S $0 ${1+"$@"}'
    if 0;

use strict;
use vars qw(@a);

my $NA = 15;

seek DATA, 0, 0;
while (<DATA>) {
    print;
    last if m/^\#endif \/\* perl \*\/$/;
}

print <<'EOF;';

#ifndef _VATMPL_H_INCLUDED_
#define _VATMPL_H_INCLUDED_ 1

EOF;

print <<'EOF;';
#define COMMA ,
#define LPAREN (
#define RPAREN )

EOF;

sub jc(@) {
    join (', ', @_);
}

sub nlist ($) {
    my $pat = shift;
    jc (map { my $ret = $pat; $ret =~ s/%/$_/g; $ret; } @a);
}

sub pdef(\@) {
    my $ar = shift;
    foreach $_ (@$ar[0 .. $#$ar - 1]) {
	my $nt = int ((71 - length ($_)) / 8);
	print $_, ($nt > 0 ? "\t" x $nt : ' '), "\\\n";
    }
    print $$ar[$#$ar], "\n" if @$ar;
}

my @lines;
push @lines, '#define VA_TEMPLATE(fn, start, end)';

my $a;
for ($a = 0; $a <= $NA; $a++) {
    local @a = (1 .. $a);
    push @lines, '', sprintf ("template<%s>", nlist 'class A%') if ($a > 0);
    push @lines, sprintf ("fn (%s)", nlist 'const A% &a%');
    push @lines, sprintf ("  start (%s) end", nlist 'a%');
}
pdef @lines;
print "\n";

@lines = ();


print "\n", '#endif /', '* !_VATMPL_H_INCLUDED_ *', '/', "\n";

__END__
# */
#endif /* perl */

#ifndef _VATMPL_H_INCLUDED_
#define _VATMPL_H_INCLUDED_ 1

#define COMMA ,
#define LPAREN (
#define RPAREN )

#define VA_TEMPLATE(fn, start, end)				\
fn ()								\
  start () end							\
								\
template<class A1>						\
fn (const A1 &a1)						\
  start (a1) end						\
								\
template<class A1, class A2>					\
fn (const A1 &a1, const A2 &a2)					\
  start (a1, a2) end						\
								\
template<class A1, class A2, class A3>				\
fn (const A1 &a1, const A2 &a2, const A3 &a3)			\
  start (a1, a2, a3) end					\
								\
template<class A1, class A2, class A3, class A4>		\
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4)	\
  start (a1, a2, a3, a4) end					\
								\
template<class A1, class A2, class A3, class A4, class A5>	\
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5) \
  start (a1, a2, a3, a4, a5) end				\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6) \
  start (a1, a2, a3, a4, a5, a6) end				\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7) \
  start (a1, a2, a3, a4, a5, a6, a7) end			\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8) \
  start (a1, a2, a3, a4, a5, a6, a7, a8) end			\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9) end		\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) end		\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10, const A11 &a11) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) end	\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10, const A11 &a11, const A12 &a12) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) end	\
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10, const A11 &a11, const A12 &a12, const A13 &a13) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) end \
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10, const A11 &a11, const A12 &a12, const A13 &a13, const A14 &a14) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) end \
								\
template<class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15> \
fn (const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10, const A11 &a11, const A12 &a12, const A13 &a13, const A14 &a14, const A15 &a15) \
  start (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) end


#endif /* !_VATMPL_H_INCLUDED_ */