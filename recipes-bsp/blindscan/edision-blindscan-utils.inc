SUMMARY = "Utilities for transponder & dvb-s/c blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

PACKAGES = "edision-blindscan-dvbs-utils-${MACHINE} edision-blindscan-dvbc-utils-${MACHINE}"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_edision-blindscan-dvbs-utils-${MACHINE} += "virtual/blindscan-dvbs"
RPROVIDES_edision-blindscan-dvbc-utils-${MACHINE} += "virtual/blindscan-dvbc"

SRC_URI = "https://github.com/edision-open/edision-blindscan-utils/releases/download/${PV}/edision-blindscan-utils-${PV}.zip"

S = "${WORKDIR}"
BLINDSCANARCH ?= ""
BLINDSCANARCH_arm = "arm-linux-gnueabihf"
BLINDSCANARCH_aarch64 = "aarch64-linux-gnu"
BLINDSCANARCH_mipsel = "mipsel-linux-gnu"

FILES_edision-blindscan-dvbs-utils-${MACHINE} = "${bindir}/blindscan"
FILES_edision-blindscan-dvbc-utils-${MACHINE} = "${bindir}/tda1002x"

INSANE_SKIP_${PN} += "already-stripped"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 ${S}/${BLINDSCANARCH}/tda1002x ${D}${bindir}
	install -m 0755 ${S}/${BLINDSCANARCH}/blindscan ${D}${bindir}
}
