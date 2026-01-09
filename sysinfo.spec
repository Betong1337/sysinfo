Name:           sysinfo
Version:        1.0.4
Release:        1%{?dist}
Summary:        Small Linux system information tool written in C

License:        MIT
URL:            https://github.com/Betong1337/sysinfo
Source0:        https://github.com/Betong1337/sysinfo/archive/refs/tags/v%{version}.tar.gz


BuildRequires:  gcc, make

%description
Sysinfo is a lightweight tool that displays basic system information
(CPU, memory, uptime, hostname, kernel and OS version). GPU info is
not included in this release.

%prep
%setup -q

%build
make

%install
mkdir -p %{buildroot}/usr/bin
cp sysinfo %{buildroot}/usr/bin/

%files
/usr/bin/sysinfo

%changelog
* Thu Jan 08 2026 Ditt Namn asp.jakob@outlook.com - 1.0.1-1
- Updated spec for COPR, removed empty Requires
