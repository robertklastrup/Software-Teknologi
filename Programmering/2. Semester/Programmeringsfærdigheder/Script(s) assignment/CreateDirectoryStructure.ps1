param (
    [Parameter(Mandatory=$true)]
    [int]$Week
)

$base = "$PSScriptRoot\Week$Week"

New-Item -ItemType Directory -Path $base -Force
New-Item -ItemType File -Path "$base\Notes.txt" -Force
New-Item -ItemType Directory -Path "$base\Exercise" -Force
New-Item -ItemType File -Path "$base\Exercise\Exercise1.ps1" -Force
New-Item -ItemType File -Path "$base\Exercise\Exercise2.ps1" -Force
