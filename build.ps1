# create "bin" directory if it does not exist
if (!(Test-Path -Path "bin")) {
    New-Item -ItemType Directory -Path "bin" | Out-Null
}

# get all c files
$sourceFiles = Get-ChildItem -Path "src" -Filter "*.c" | ForEach-Object { $_.FullName }

# compile to bin
# gcc $sourceFiles -o bin/cutie -Wall -Wextra -Werror -std=c11 -O2
gcc $sourceFiles -o bin/cutie -Wall -Wextra -std=c11 -O2

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build successful. Executable created at 'bin/cutie.exe'" -ForegroundColor Green
} else {
    Write-Host "Build failed." -ForegroundColor Red
}