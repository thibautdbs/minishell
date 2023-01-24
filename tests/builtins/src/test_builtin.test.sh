#!/usr/bin/env bash

test_dummy1()
{
	OUT=$(mktemp -p "${SHUNIT_TMPDIR}");
	ERR=$(mktemp -p "${SHUNIT_TMPDIR}");

	my::run_builtin test_builtin >${OUT} 2>${ERR};

	assertEquals 0 ${?};
	assertEquals yoyoyo "$(cat "${OUT}")";
}
